/*
 * coal - An object oriented general purpose library for GNU-C
 * Copyright (C) 2012 Truls Edvard Stokke
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <errno.h>
#include <stdbool.h>
#include <stddef.h> /* NULL */

#include <pthread.h>

#include <coal/private/atomic.h>
#include <coal/private/library.h>            /* LIBRARY_PREFIX, LIBRARY_MODSEP */
#include <coal/private/object_orientation.h> /* SETUP_CLASS_DESCRIPTION */
#include <coal/private/virtual_methods.h>    /* CheckAndThrowMissingMethod */

#include <coal/base/Object.h>
#include <coal/base/Metaclass.h>

#include <coal/error/IllegalStateException.h>
#include <coal/error/OutOfMemoryError.h>

#include <coal/parallel/DeadlockException.h>

#include <coal/private/cleanup_stack.h>

#include <coal/parallel/Thread.h>
#include <coal/parallel/Thread/Thread.rep.h>

static void * Thread_target (void * args) {
  class(Thread) * self = args;
  void * retval;

  pthread_cleanup_push(coal_private_cleanup_run_all, NULL);
  retval = self->start_routine(self->args);
  pthread_cleanup_pop(1);

  return retval;
}

/* ugly special treatment of the main thread */
static void Thread_Main_cleanup (void)
  __attribute__ ((destructor));

static void Thread_Main_cleanup (void) {
  coal_private_cleanup_run_all(NULL);
}

/* Thread implements base.Object methods */

var Thread_constructor (var _self, va_list * args) {
  class(Thread) * self = _self;

  self->start_routine = va_arg(*args, void *(*)(void *));
  self->args = va_arg(*args, void *);

  self->active = false;

  return _self;
}

var Thread_destructor (var _self) {
  class(Thread) * self = _self;
  pthread_t this = pthread_self();

  if (pthread_equal(this, self->thread))
    /* if some genius decides to delete the same thread he is
       calling with we stop him. throwing something would be
       better here but alas throwing things from destructors
       is bad for your health */
    /* a smart person could probably find some way to convey
       the message to the user that something fishy is going
       on */
    return NULL;

  return _self;
}

/* Thread implements parallel.Thread methods */

void coal_parallel_Thread_exit (void * retval) {
  /* FIXME: do our attributes get deallocated here? that
     would be magical but unlikely. we have to delete
     ourselves and only then call pthread_exit. */
  /* FIXED: we no longer carry attributes, so much for
     customization and usability. */
  /* do we delete our parallel.Thread object? no, we have not
     created it so we do technically not hold a reference to
     it */
  pthread_exit(retval);
}

void * coal_parallel_Thread_join (val _thread) {
  const class(Thread) * thread = _thread;
  void * retval;
  int error;

  CheckAndThrowMissingMethod(_thread, coal_parallel_Thread());

  if (! thread->active)
    coal_throw(coal_new(coal_error_IllegalStateException(),
			"%s: attempted to join with a thread that has not yet started",
			__func__));

  error = pthread_join(thread->thread, &retval);

  if (error) {
    switch (error) {
    case EDEADLK:
      /*
       * EDEADLK: ``A  deadlock  was  detected (e.g., two
       * threads tried to join with each other); or thread
       * specifies the calling thread.''
       */
      coal_throw(coal_new(coal_parallel_DeadlockException(),
			  "%s: attempted join would cause a deadlock",
			  __func__));
      break;
    case EINVAL:
      /*
       * EINVAL: ``thread is not a joinable thread.''
       * parallel.Thread objects are either inactive or are
       * valid joinable threads.
       *
       * EINVAL: ``Another thread is already waiting to join
       * with this thread.''
       */
      /* the choice of exception here is dubious */
      coal_throw(coal_new(coal_error_IllegalStateException(),
			  "%s: attempted to join with a thread that is already being joined by another thread",
			  __func__));
      break;
    case ESRCH:
      /*
       * ESRCH: ``No thread with the ID thread could be
       * found.''
       * parallel.Thread objects are either inactive or carry
       * a valid thread-id.
       */
      (void) 0;
      break;
    default:
      /* we never reach this point */
      break;
    }
  }

  return retval;
}

void coal_parallel_Thread_start (var _self) {
  class(Thread) * self = _self;
  int error;

  CheckAndThrowMissingMethod(_self, coal_parallel_Thread());

  /* safeguard */
  while (true) {
    if (self->active)
      coal_throw(coal_new(coal_error_IllegalStateException(),
			  "%s: threads may only be started once",
			  __func__));

    if (atomic_cas(&self->active, false, true))
      break;
  }

  error = pthread_create(&self->thread, NULL /* default */,
			 Thread_target, self);

  if (error) {
    switch (error) {
    case EINVAL:
      /*
       * EINVAL: ``Invalid settings in attr.''
       * This shouldn't happen since we currently use default
       * attributes.
       */
      (void) 0;
      break;
    case EPERM:
      /*
       * EPERM: ``No permission to set the scheduling policy
       * and parameters specified in attr.''
       * This shouldn't happen since we currently use default
       * attributes.
       */
      /* intentional fall through */
    case EAGAIN:
      coal_throw(coal_new(coal_error_OutOfMemoryError(),
			  "%s: unable to start new thread, out of system resources",
			  __func__));
      break;
    default:
      /* this never happens */
      break;
    }
  }
}

SETUP_CLASS_DESCRIPTION(coal_parallel_Thread,
			coal_base_Metaclass(),
			LIBRARY_PREFIX "parallel" LIBRARY_MODSEP "Thread",
			coal_base_Object(),
			sizeof(class(Thread)),
			/* Object */
			INHERIT_METHOD,     /* cmp */
			Thread_constructor,
			Thread_destructor,
			INHERIT_METHOD,     /* equals */
			INHERIT_METHOD,     /* hashCode */
			INHERIT_METHOD);    /* toString */

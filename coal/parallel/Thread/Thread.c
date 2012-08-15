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

#include <pthread.h>

#include <coal/private/atomic.h>
#include <coal/private/library.h>            /* LIBRARY_STR */
#include <coal/private/object_orientation.h> /* SETUP_CLASS_DESCRIPTION */
#include <coal/private/virtual_methods.h>    /* CheckAndThrowMissingMethod */

#include <coal/base/Object.h>
#include <coal/base/Metaclass.h>

#include <coal/error/IllegalStateException.h>

#include <coal/parallel/Thread.h>
#include <coal/parallel/Thread/Thread.rep.h>

/* Thread implements base.Object methods */

var Thread_constructor (var _self, va_list * args) {
  class(Thread) * self = _self;

  /* FIXME: ENOMEM might happen here, very inconvenient in the
     middle of a constructor, might be a good idea to split
     this up into another method, fix this later. */
  (void) pthread_attr_init(&self->attr);

  self->start_routine = va_arg(*args, void *(*)(void *));
  self->args = va_arg(*args, void *);

  self->active = false;

  return _self;
}

var Thread_destructor (var _self) {
  class(Thread) * self = _self;

  if (self->active)
    /* FIXME: a host of different errors might happen here
       as well, right in the middle of a destructor, very
       unhealthy, fix later. */
    (void) coal_parallel_Thread_join(_self);

  /* FIXME: EINVAL might happen here, again in the middle
     of a destructor, very unhealthy, if we're good we can
     ensure that self->attr is always valid before the
     destructor is called. */
  (void) pthread_attr_destroy(&self->attr);

  return _self;
}

/* Thread implements parallel.Thread methods */

void coal_parallel_Thread_exit (void * retval) {
  /* FIXME: do our attributes get deallocated here? that
     would be magical but unlikely. we have to delete
     ourselves and only then call pthread_exit. */
  pthread_exit(retval);
}

void * coal_parallel_Thread_join (val _thread) {
  const class(Thread) * thread = _thread;
  void * retval;

  CheckAndThrowMissingMethod(_thread, coal_parallel_Thread());

  if (! thread->active)
    coal_throw(coal_new(coal_error_IllegalStateException(),
			"%s: attempted to join with a thread that has not yet started",
			__func__));

  /*
   * FIXME: tons of things can go wrong here
   *
   * errno
   *   \
   *    |- EDEADLK: circular join chain
   *    |- EINVAL: thread not joinable (not possible yet)
   *    |- EINVAL: another thread is attempting to join with
   *    |          this thread
   *    |- ESRCH: no thread with that thread id exists
   *    |         (shouldn't happen)
   *
   * Check these and throw the appropriate exception/error.
   */
  (void) pthread_join(thread->thread, &retval);

  return retval;
}

void coal_parallel_Thread_start (var _self) {
  class(Thread) * self = _self;

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

  /* FIXME: lots of things might go wrong here, find them
     and throw appropriate exception/error. */
  (void) pthread_create(&self->thread, &self->attr,
			self->start_routine, self->args);
}

SETUP_CLASS_DESCRIPTION(coal_parallel_Thread,
			coal_base_Metaclass(),
			LIBRARY_STR ".parallel.Thread",
			coal_base_Object(),
			sizeof(class(Thread)),
			/* Object */
			INHERIT_METHOD,     /* cmp */
			Thread_constructor,
			Thread_destructor,
			INHERIT_METHOD,     /* equals */
			INHERIT_METHOD,     /* hashCode */
			INHERIT_METHOD);    /* toString */

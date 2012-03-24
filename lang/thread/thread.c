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

#include <coal/core/atomic.h>
#include <coal/core/implementation.h>
#include <coal/lang/IllegalStateException.h>
#include <coal/lang/OutOfMemoryError.h>

#include <coal/lang/thread.h>
#include <coal/lang/thread/thread.rep>

var thread_constructor (var _self, va_list * app) {
  class(thread) * self = _self;

  pthread_attr_init(&self->attr);
  self->start_routine = va_arg(*app, typeof(self->start_routine));
  self->arg = va_arg(*app, void *);

  self->active = false;

  return _self;
}

var thread_destructor (var _self) {
  class(thread) * self = _self;

  if (self->active)
    pthread_join(self->thread, NULL);

  pthread_attr_destroy(&self->attr);

  return _self;
}

void coal_lang_thread_exit (void) {
  pthread_exit(NULL);
}

void coal_lang_thread_join (var _self) {
  class(thread) * self = _self;

  CheckAndThrowMissingMethodException("coal_lang_thread_join", _self, coal_lang_thread());

  if (!self->active)
    coal_throw(coal_new(coal_lang_IllegalStateException(),
			"coal_lang_thread_join: attempted to join with a thread that hasn't been started yet"));

  pthread_join(self->thread, NULL);
}

void coal_lang_thread_start (var _self) {
  class(thread) * self = _self;

  CheckAndThrowMissingMethodException("coal_lang_thread_start", _self, coal_lang_thread());

  /* safeguard */
  while (true) {
    if (self->active)
      coal_throw(coal_new(coal_lang_IllegalStateException(),
			  "coal_lang_thread_start: threads may only be started once"));

    if (atomic_cas(&self->active, false, true))
      break;
  }

  if (pthread_create(&self->thread, &self->attr,
		     self->start_routine, self->arg))
    /* until the user gains access to
       setting attributes the only
       error here must be EAGAIN. */
    coal_throw(coal_new(coal_lang_OutOfMemoryError(),
			"coal_lang_thread_start: unable to start thread, out of system resources"));
}

SETUP_CLASS_DESCRIPTION(coal_lang_thread,
			coal_lang_metaclass(),
			LIBRARY_STR ".lang.thread",
			coal_lang_object(),
			sizeof(class(thread)),
			INHERIT_METHOD,
			thread_constructor,
			thread_destructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);

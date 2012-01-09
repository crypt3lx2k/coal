#include <pthread.h>

#include <coal/core/atomic.h>
#include <coal/core/implementation.h>
#include <coal/lang/IllegalStateException.h>

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

  pthread_join(self->thread, NULL);
  pthread_attr_destroy(&self->attr);

  return _self;
}

void coal_lang_thread_exit (void) {
  pthread_exit(NULL);
}

void coal_lang_thread_join (var _self) {
  class(thread) * self = _self;

  pthread_join(self->thread, NULL);
}

void coal_lang_thread_start (var _self) {
  class(thread) * self = _self;

  /* safeguard */
  while (true) {
    if (self->active)
      coal_throw(coal_new(coal_lang_IllegalStateException(),
			  "coal_lang_thread_start: threads may only be started once"));

    if (atomic_cas(&self->active, false, true))
      break;
  }

  (void) pthread_create(&self->thread,
			&self->attr,
			self->start_routine,
			self->arg);
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

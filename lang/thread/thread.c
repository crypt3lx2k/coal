#include <coal/core/implementation.h>

#include <coal/lang/thread.h>
#include <coal/lang/thread/thread.rep>

var thread_constructor (var _self, va_list * app) {
  class(thread) * self = _self;

  pthread_attr_init(&self->attr);
  self->start_routine = va_arg(*app, typeof(self->start_routine));
  self->arg = va_arg(*app, void *);

  return _self;
}

var thread_destructor (var _self) {
  class(thread) * self = _self;

  pthread_join(self->thread, NULL);
  pthread_attr_destroy(&self->attr);

  return _self;
}

void coal_lang_thread_run (var _self) {
  class(thread) * self = _self;

  (void) pthread_create(&self->thread,
			&self->attr,
			self->start_routine,
			self->arg);
}

void coal_lang_thread_join (var _self) {
  class(thread) * self = _self;

  pthread_join(self->thread, NULL);
}

static const var thread__ = NULL;

const var coal_lang_thread (void) {
  return thread__ != NULL ? thread__ :
    (thread__ = coal_new(coal_lang_metaclass(),
			 LIBRARY_STR ".lang.thread",
			 coal_lang_object(),
			 sizeof(class(thread)),
			 INHERIT_METHOD,
			 thread_constructor,
			 thread_destructor,
			 INHERIT_METHOD,
			 INHERIT_METHOD,
			 INHERIT_METHOD));
}
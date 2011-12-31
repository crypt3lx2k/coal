#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#include <coal/core/implementation.h>
#include <coal/lang/OutOfMemoryError.h>

#include <coal/lang/throwable.h>
#include <coal/lang/throwable/throwable.rep>

var throwable_constructor(var _self, va_list * app) {
  class(throwable) * self = _self;
  const char       * fmt  = va_arg(*app, const char *);
  va_list            copy;

  va_copy(copy, *app);

  if (vasprintf(&self->message, fmt, copy) == -1)
    lib(throw)(lib(new)(lang(OutOfMemoryError)(),
			"throwable_constructor: string allocation failed."));

  va_end(copy);

  return _self;
}

var throwable_destructor(var _self) {
  class(throwable) * self = _self;

  free(self->message);

  return _self;
}

var throwable_toString(const var _self) {
  const class(metaclass) * class = lang(getClass)(_self);
  const class(throwable) * self  = _self;

  return lib(new)(lang(string)(),
		  "%s: %s",
		  class->name,
		  self->message);
}

static const var throwable__ = NULL;

const var lang(throwable) (void) {
  return throwable__ != NULL ? throwable__ :
    (throwable__ = lib(new)(lang(metaclass)(),
			    LIBRARY_STR ".lang.throwable",
			    lang(object)(),
			    sizeof(class(throwable)),
			    INHERIT_METHOD,
			    throwable_constructor,
			    throwable_destructor,
			    INHERIT_METHOD,
			    INHERIT_METHOD,
			    throwable_toString));
}

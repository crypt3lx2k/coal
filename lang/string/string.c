#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <coal/implementation.h>

#include <coal/lang/string.h>
#include <coal/lang/string/string.rep>

int string_cmp (const var _self, const var _other) {
  const class(string) * self  = _self;
  const class(string) * other = _other;

  return strcmp(self->str, other->str);
}

var string_constructor (var _self, va_list * app) {
  class(string) * self = _self;
  const char    * fmt = va_arg(*app, const char *);
  va_list         copy;

  va_copy(copy, *app);
  vasprintf(&self->str,
	    fmt,
	    copy);
  va_end(copy);

  self->len = strlen(self->str);
  return _self;
}

var string_destructor (var _self) {
  class(string) * self = _self;

  free(self->str);
  self->len = 0;

  return _self;
}

bool string_equals (const var _self, const var _other) {
  const class(string) * self  = _self;
  const class(string) * other = _other;

  if (_self == _other)
    return true;
  else if (lang(getClass)(other) != lang(string)())
    return false;
  else if (self->len != other->len)
    return false;
  else
    return strcmp(self->str, other->str) == 0;
}

int string_hashCode(const var _self) {
  const class(string) * self = _self;
  char * str = self->str;
  size_t len = self->len;

  register int i, x, m;

  if (str[0] == '\0')
    return 0;

  x = str[0] << 7;
  m = 1000003;

  for (i = 0; i < (int) len; i++)
    x = (x*m)^str[i];

  return x;
}

var string_toString(const var self) {
  return lib(acquire)((var) self);
}

const char * lang_string(chars) (const var _self) {
  const class(string) * self = _self;

  return self->str;
}

static const var string__ = NULL;

const var lang(string) (void) {
  return string__ ? string__ :
    (string__ = lib(new)(lang(metaclass)(),
			 LIBRARY_STR ".lang.string",
			 lang(object)(),
			 sizeof(class(string)),
			 string_cmp,
			 string_constructor,
			 string_destructor,
			 string_equals,
			 string_hashCode,
			 string_toString));
}
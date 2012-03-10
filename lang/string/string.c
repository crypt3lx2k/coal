#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <coal/core/implementation.h>
#include <coal/lang/OutOfMemoryError.h>

#include <coal/lang/iterable.h>
#include <coal/util/iterator.h>

#include <coal/lang/string.h>
#include <coal/lang/string/string.rep>
#include <coal/lang/string/string_metaclass.rep>

/* override lang.object methods */

int string_cmp (const var _self, const var _other) {
  const class(string) * self  = _self;
  const class(string) * other = _other;

  return strcmp(self->str, other->str);
}

var string_constructor (var _self, va_list * app) {
  class(string) * self = _self;
  const char * fmt = va_arg(*app, const char *);
  va_list copy;

  va_copy(copy, *app);

  if (vasprintf(&self->str, fmt, copy) == -1)
    coal_throw(coal_new(coal_lang_OutOfMemoryError(),
			"string_constructor: string allocation failed."));

  va_end(copy);

  self->len = strlen(self->str);
  return _self;
}

var string_destructor (var _self) {
  class(string) * self = _self;

  free(self->str);
  self->str = NULL;
  self->len = 0;

  return _self;
}

bool string_equals (const var _self, const var _other) {
  const class(string) * self  = _self;
  const class(string) * other = _other;

  if (self->len != other->len)
    return false;
  else
    return strncmp(self->str, other->str,
		   MIN(self->len, other->len)) == 0;
}

int string_hashCode(const var _self) {
  const class(string) * self = _self;
  const char * str = self->str;
  const size_t len = self->len;

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
  return coal_acquire((var) self);
}

/* lang.string methods */

/* chars and length are
   statically linked */

var string_concat (var _self, var _other) {
  class(string) * self  = _self;
  class(string) * other = _other;
  class(string) * res;
  size_t len;

  len = self->len + other->len;

  if (GET_REFERENCE_COUNT(_self) == 1) {
    /* we currently hold the last reference
       to the object, this means that we may
       reuse the space already allocated for it */
    res = coal_acquire(_self);
    res->str =
      coal_core_realloc(res->str, (len+1) * sizeof(char));
  } else {
    /* we don't currently hold the last reference
       of the object and have to allocate a copy */
    res = coal_new(coal_lang_string(), "");
    string_destructor(res);

    res->str = coal_core_malloc((len+1) * sizeof(char));
    memcpy(res->str, self->str, self->len);
  }

  memcpy(res->str + self->len, other->str, other->len);
  res->str[len] = '\0';
  res->len = len;

  return res;
}

var string_join (var self, const var iterable) {
  var s = coal_new(coal_lang_string(), "");
  var i = coal_lang_iterable_iterator(iterable);

  while (coal_util_iterator_hasNext(i)) {
    var elem = coal_util_iterator_next(i);

    s = coal_lang_string_concat(s, coal_lang_toString(elem));

    if (coal_util_iterator_hasNext(i))
      s = coal_lang_string_concat(s, coal_acquire(self));
  }

  coal_del(i);
  return s;
}


SETUP_CLASS_DESCRIPTION(coal_lang_string,
			coal_lang_string_metaclass(),
			LIBRARY_STR ".lang.string",
			coal_lang_object(),
			sizeof(class(string)),
			/* object */
			string_cmp,
			string_constructor,
			string_destructor,
			string_equals,
			string_hashCode,
			string_toString,
			/* string */
			string_concat,
			string_join);

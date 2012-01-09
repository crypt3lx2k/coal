#include <coal/core/implementation.h>

#include <coal/util/iterator.h>
#include <coal/lang/string/string_iterator.rep>

var string_iterator_constructor (var _self, va_list * app) {
  class(string_iterator) * self = _self;

  self->str = va_arg(*app, const char *);
  self->len = va_arg(*app, size_t);
  self->current = 0;

  return _self;
}

bool string_iterator_hasNext (const var _self) {
  const class(string_iterator) * self = _self;

  return self->current < self->len;
}

var string_iterator_next (var _self) {
  class(string_iterator) * self = _self;

  return (var) (int) self->str[self->current++];
}

SETUP_CLASS_DESCRIPTION(coal_lang_string_iterator,
			coal_util_iterator(),
			LIBRARY_STR ".lang.string.iterator",
			coal_lang_object(),
			sizeof(class(string_iterator)),
			INHERIT_METHOD,
			string_iterator_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			string_iterator_hasNext,
			string_iterator_next);

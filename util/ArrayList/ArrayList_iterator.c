#include <coal/core/implementation.h>

#include <coal/util/iterator.h>
#include <coal/util/ArrayList/ArrayList_iterator.rep>

var ArrayList_iterator_constructor (var _self, va_list * app) {
  class(ArrayList_iterator) * self = _self;

  self->base = va_arg(*app, var *);
  self->head = va_arg(*app, var *);

  return _self;
}

bool ArrayList_iterator_hasNext (const var _self) {
  const class(ArrayList_iterator) * self = _self;

  return self->base < self->head;
}

var ArrayList_iterator_next (var _self) {
  class(ArrayList_iterator) * self = _self;

  return *self->base++;
}

SETUP_CLASS_DESCRIPTION(coal_util_ArrayList_iterator,
			coal_util_iterator(),
			LIBRARY_STR ".util.ArrayList.iterator",
			coal_lang_object(),
			sizeof(class(ArrayList_iterator)),
			INHERIT_METHOD,
			ArrayList_iterator_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			ArrayList_iterator_hasNext,
			ArrayList_iterator_next);

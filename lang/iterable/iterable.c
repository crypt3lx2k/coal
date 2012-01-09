#include <coal/core/implementation.h>

#include <coal/lang/iterable.h>
#include <coal/lang/iterable/iterable.rep>

var iterable_constructor (var _self, va_list * app) {
  const class(metaclass) * class = coal_lang_iterable();
  class(iterable) * self = _self;

  class->super->constructor(_self, app);

  OverrideMethod(self, iterator);

  return _self;
}

var coal_lang_iterable_iterator (const var _self) {
  const class(iterable) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_lang_iterable_iterator", class, coal_lang_iterable());

  return class->iterator(_self);
}

SETUP_CLASS_DESCRIPTION(coal_lang_iterable,
			coal_lang_metaclass(),
			LIBRARY_STR ".lang.iterable",
			coal_lang_metaclass(),
			sizeof(class(iterable)),
			INHERIT_METHOD,
			iterable_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);
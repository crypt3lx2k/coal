#include <coal/core/implementation.h>

#include <coal/util/iterator.h>
#include <coal/util/iterator/iterator.rep>

var iterator_constructor (var _self, va_list * app) {
  const class(metaclass) * class = coal_util_iterator();
  class(iterator) * self = _self;

  class->super->constructor(_self, app);

  OverrideMethod(self, hasNext);
  OverrideMethod(self, next);

  return _self;
}

bool coal_util_iterator_hasNext (const var _self) {
  const class(iterator) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_iterator_hasNext", class, coal_util_iterator());

  return class->hasNext(_self);
}

var coal_util_iterator_next (var _self) {
  const class(iterator) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_iterator_next", class, coal_util_iterator());

  return class->next(_self);
}

SETUP_CLASS_DESCRIPTION(coal_util_iterator,
			coal_lang_metaclass(),
			LIBRARY_STR ".util.iterator",
			coal_lang_metaclass(),
			sizeof(class(iterator)),
			INHERIT_METHOD,
			iterator_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);
#include <coal/core/implementation.h>

#include <coal/lang/AbstractInstantiationError.h>

#include <coal/lang/abstract.h>
#include <coal/lang/abstract/abstract.rep>

var abstract_constructor (var self, va_list * app) {
  const class(metaclass) * class = coal_lang_getClass(self);

  /* deallocate */
  coal_del(self);
  va_end(*app);

  coal_throw(coal_new(coal_lang_AbstractInstantiationError(),
		      "abstract_constructor: an attempt was made to instantiate abstract class %s.",
		      class->name));
}

SETUP_CLASS_DESCRIPTION(coal_lang_abstract,
			coal_lang_metaclass(),
			LIBRARY_STR ".lang.abstract",
			coal_lang_object(),
			sizeof(class(abstract)),
			INHERIT_METHOD,
			abstract_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);

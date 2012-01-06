#include <string.h>
#include <coal/core/implementation.h>

#include <coal/core/classes/subclass.h>
#include <coal/core/classes/subclass/subclass.rep>

var subclass_constructor (var _self, va_list * app) {
  class(metaclass) * self = _self;
  const class(metaclass) * super;
  const char * name;

  name  = va_arg(*app, const char *);
  super = va_arg(*app, const class(metaclass) *);

  memcpy(self,
	 super,
	 coal_lang_getSize(super));

  self->name  = name;
  self->super = super;

  return _self;
}

SETUP_CLASS_DESCRIPTION(coal_core_subclass,
			coal_lang_metaclass(),
			LIBRARY_STR ".core.subclass",
			coal_lang_metaclass(),
			sizeof(class(subclass)),
			INHERIT_METHOD,
			subclass_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);

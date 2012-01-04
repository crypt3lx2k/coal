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

static const var subclass__ = NULL;

const var coal_core_subclass (void) {
  return subclass__ ? subclass__ :
    (subclass__ = coal_new(coal_lang_metaclass(),
			   LIBRARY_STR ".core.classes.subclass",
			   coal_lang_metaclass(),
			   sizeof(class(subclass)),
			   INHERIT_METHOD,
			   subclass_constructor,
			   INHERIT_METHOD,
			   INHERIT_METHOD,
			   INHERIT_METHOD,
			   INHERIT_METHOD,
			   INHERIT_METHOD));
}

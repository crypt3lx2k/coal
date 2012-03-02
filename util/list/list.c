#include <coal/core/implementation.h>
#include <coal/util/collection.h>

#include <coal/util/list.h>
#include <coal/util/list/list.rep>

var list_constructor (var _self, va_list * app) {
  const class(metaclass) * class = coal_util_list();
  class(list) * self = _self;

  class->super->constructor(_self, app);

  OverrideMethod(self, get);
  OverrideMethod(self, insert);
  OverrideMethod(self, set);

  return self;
}

var coal_util_list_get (const var _self, int index) {
  const class(list) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_list_get", class, coal_util_list());

  return class->get(_self, index);
}

bool coal_util_list_insert (var _self, int index, var elem) {
  const class(list) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_list_insert", class, coal_util_list());

  return class->insert(_self, index, elem);
}

var coal_util_list_set (var _self, int index, var elem) {
  const class(list) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_list_set", class, coal_util_list());

  return class->set(_self, index, elem);
}

SETUP_CLASS_DESCRIPTION(coal_util_list,
			coal_lang_metaclass(),
			LIBRARY_STR ".util.list",
			coal_util_collection(),
			sizeof(class(list)),
			INHERIT_METHOD,
			list_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);

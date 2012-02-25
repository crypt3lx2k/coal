#include <coal/core/implementation.h>
#include <coal/lang/iterable.h>

#include <coal/util/collection.h>
#include <coal/util/collection/collection.rep>

var collection_constructor (var _self, va_list * app) {
  const class(metaclass) * class = coal_util_collection();
  class(collection) * self = _self;

  class->super->constructor(_self, app);

  OverrideMethod(self, contains);
  OverrideMethod(self, isEmpty);
  OverrideMethod(self, size);

  return self;
}

bool coal_util_collection_contains (const var _self, const var object) {
  const class(collection) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_collection_contains", class, coal_util_collection());

  return class->contains(_self, object);
}

bool coal_util_collection_isEmpty (const var _self) {
  const class(collection) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_collection_isEmpty", class, coal_util_collection());

  return class->isEmpty(_self);
}

int coal_util_collection_size (const var _self) {
  const class(collection) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_collection_size", class, coal_util_collection());

  return class->size(_self);
}

SETUP_CLASS_DESCRIPTION(coal_util_collection,
			coal_lang_metaclass(),
			LIBRARY_STR ".util.collection",
			coal_lang_iterable(),
			sizeof(class(collection)),
			INHERIT_METHOD,
			collection_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);

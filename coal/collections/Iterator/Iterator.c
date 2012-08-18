#include <coal/base/Metaclass.h>

#include <coal/private/library.h>
#include <coal/private/virtual_methods.h>

#include <coal/collections/Iterator.h>
#include <coal/collections/Iterator/Iterator.rep.h>

/* collections.Iterator implements base.Object methods */

var Iterator_constructor (var _self, va_list * args) {
  const class(Metaclass) * class;
  class(Iterator) * self = _self;

  class = coal_collections_Iterator();
  class->super->constructor(_self, args);

  OverrideMethod(self, args, hasNext);
  OverrideMethod(self, args, next);

  return _self;
}

/* selector functions */

bool coal_collections_Iterator_hasNext (val self) {
  const class(Iterator) * class;
  class = coal_base_Object_getClass(self);

  CheckAndThrowMissingMethod(class,
			     coal_collections_Iterator());

  return class->hasNext(self);
}

val coal_collections_Iterator_next (var self) {
  const class(Iterator) * class;
  class = coal_base_Object_getClass(self);

  CheckAndThrowMissingMethod(class,
			     coal_collections_Iterator());

  return class->next(self);
}

SETUP_CLASS_DESCRIPTION(coal_collections_Iterator,
			coal_base_Metaclass(),
			LIBRARY_STR ".collections.Iterator",
			coal_base_Metaclass(),
			sizeof(class(Iterator)),
			/* Object */
			INHERIT_METHOD,       /* cmp */
			Iterator_constructor,
			INHERIT_METHOD,       /* destructor */
			INHERIT_METHOD,       /* equals */
			INHERIT_METHOD,       /* hashCode */
			INHERIT_METHOD);      /* toString */

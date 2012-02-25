#include <coal/core/implementation.h>

#include <coal/util/collection.h>
#include <coal/util/AbstractCollection.h>

#include <coal/util/ArrayList.h>
#include <coal/util/ArrayList/ArrayList.rep>
#include <coal/util/ArrayList/ArrayList_iterator.rep>

/* override lang.object methods */

var ArrayList_constructor (var _self, va_list * app) {
  class(ArrayList) * self = _self;
  size_t size = va_arg(*app, size_t);

  self->base = size ? coal_core_malloc(size) : NULL;
  self->head = self->base;
  self->end  = self->base + size;

  return _self;
}

var ArrayList_destructor (var _self) {
  class(ArrayList) * self = _self;

  free(self->base);
  self->base = NULL;
  self->head = NULL;
  self->end  = NULL;

  return _self;
}

/* lang.iterable methods */

var ArrayList_iterator (const var _self) {
  const class(ArrayList) * self = _self;

  return coal_new(coal_util_ArrayList_iterator(),
		  self->base,
		  self->head);
}

/* util.collection methods */

int ArrayList_size (const var _self) {
  const class(ArrayList) * self = _self;

  return self->head - self->base;
}

/* util.ArrayList methods */

/* ... */

SETUP_CLASS_DESCRIPTION(coal_util_ArrayList,
			coal_util_collection(),
			LIBRARY_STR ".util.ArrayList",
			coal_util_AbstractCollection(),
			sizeof(class(ArrayList)),
			/* object */
			INHERIT_METHOD,
			ArrayList_constructor,
			ArrayList_destructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			/* iterable */
			ArrayList_iterator,
			/* collection */
			INHERIT_METHOD,
			INHERIT_METHOD,
			ArrayList_size);

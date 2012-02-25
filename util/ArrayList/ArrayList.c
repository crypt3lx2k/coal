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

  self->base = size ? coal_core_malloc(size * sizeof(var)) : NULL;
  self->head = self->base;
  self->end  = self->base + size;

  return _self;
}

var ArrayList_destructor (var _self) {
  var * i;
  class(ArrayList) * self = _self;

  for (i = self->base; i < self->head; i++)
    coal_del(*i);

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

/* temporary, I'll probably let this
   be chosen at constructor time */
#define RESIZE_FACTOR 0.70

static inline ptrdiff_t __attribute__ ((pure))
ArrayList_newSize (ptrdiff_t old_size) {
  return ((RESIZE_FACTOR + 1) * old_size) + 1;
}

bool ArrayList_add (var _self, const var object) {
  class(ArrayList) * self = _self;

  if (self->head == self->end) {
    ptrdiff_t offset = self->end - self->base;

    self->base = coal_core_realloc(self->base,
				   ArrayList_newSize(offset) *
				   sizeof(var));
    self->head = self->base + offset;
    self->end  = self->base + ArrayList_newSize(offset);
  }

  *self->head++ = (var) object;

  return true;
}

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
			ArrayList_add,
			INHERIT_METHOD, /* clear */
			INHERIT_METHOD, /* contains */
			INHERIT_METHOD, /* isEmpty */
			INHERIT_METHOD, /* remove */
			ArrayList_size);

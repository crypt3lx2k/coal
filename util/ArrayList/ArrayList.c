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

  self->resize_factor = va_arg(*app, float);

  /* default sane value */
  if (! self->resize_factor > 0.0)
    self->resize_factor = 0.70;

  self->base = size ? coal_core_malloc(size * sizeof(var)) : NULL;
  self->head = self->base;
  self->end  = self->base + size;

  return _self;
}

var ArrayList_destructor (var _self) {
  class(ArrayList) * self = _self;
  int i;
  int size = self->head - self->base;

  for (i = 0; i < size; i++)
    coal_del(self->base[i]);

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

bool ArrayList_add (var _self, const var object) {
  class(ArrayList) * self = _self;

  if (self->head == self->end) {
    ptrdiff_t offset = self->end - self->base;

#define newSize(oldsize) ((ptrdiff_t) (self->resize_factor + 1) * (oldsize) + 1)

    self->base = coal_core_realloc(self->base, newSize(offset) * sizeof(var));
    self->head = self->base + offset;
    self->end  = self->base + newSize(offset);

#undef newSize
  }

  *self->head++ = (var) object;

  return true;
}

void ArrayList_clear (var _self) {
  class(ArrayList) * self = _self;
  int i;
  int size = self->head - self->base;

  for (i = 0; i < size ; i++)
    coal_del(self->base[i]);

  self->head = self->base;
}

bool ArrayList_contains (const var _self, const var object) {
  const class(ArrayList) * self = _self;
  int i;
  int size = self->head - self->base;

  for (i = 0; i < size; i++)
    if (coal_lang_equals(self->base[i], object))
      return true;

  return false;
}

bool ArrayList_isEmpty (const var _self) {
  const class(ArrayList) * self = _self;

  return self->base == self->head;
}

bool ArrayList_remove (var _self, const var object) {
  class(ArrayList) * self = _self;
  int i, j;
  int size = self->head - self->base;

  for (i = 0; i < size; i++) {
    if (coal_lang_equals(self->base[i], object)) {
      coal_del(self->base[i]);

      for (j = i; j < size - 1; j++)
	self->base[j] = self->base[j+1];

      self->head -= 1;
      return true;
    }
  }

  return false;
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
			ArrayList_clear,
			ArrayList_contains,
			ArrayList_isEmpty,
			ArrayList_remove,
			ArrayList_size);

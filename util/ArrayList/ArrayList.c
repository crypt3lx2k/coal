/*
 * coal - An object oriented general purpose library for GNU-C
 * Copyright (C) 2012 Truls Edvard Stokke
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <coal/core/implementation.h>

#include <coal/lang/IndexOutOfBoundsException.h>

#include <coal/util/list.h>
#include <coal/util/AbstractList.h>

#include <coal/util/ArrayList.h>
#include <coal/util/ArrayList/ArrayList.rep>
#include <coal/util/ArrayList/ArrayList_iterator.rep>

/* override lang.object methods */

var ArrayList_constructor (var _self, va_list * app) {
  class(ArrayList) * self = _self;
  size_t size = va_arg(*app, size_t);

  /* floats are promoted to double when passed
     through a variable argument list */
  self->resize_factor = (float) va_arg(*app, double);

  /* default sane value */
  if (self->resize_factor <= 0.0)
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

bool ArrayList_add (var _self, var object) {
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

bool ArrayList_contains (const var _self, var object) {
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

bool ArrayList_remove (var _self, var object) {
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

/* util.list methods */

var ArrayList_get (const var _self, int index) {
  const class(ArrayList) * self = _self;
  int size = self->head - self->base;

  if (index >= size || index < 0)
    coal_throw(coal_new(coal_lang_IndexOutOfBoundsException(),
			"ArrayList_get: index out of bounds"));

  return self->base[index];
}

bool ArrayList_insert (var _self, int index, var elem) {
  class(ArrayList) * self = _self;
  int i;
  var s;
  int size = self->head - self->base;

  if (index > size || index < 0)
    coal_throw(coal_new(coal_lang_IndexOutOfBoundsException(),
			"ArrayList_insert: index out of bounds"));

  if (index == size)
    return ArrayList_add(_self, elem);

  s = self->base[size-1];

  for (i = size-1; i > index; i--)
    self->base[i] = self->base[i-1];

  self->base[i] = elem;

  return ArrayList_add(_self, s);
}

var ArrayList_set (var _self, int index, var elem) {
  class(ArrayList) * self = _self;
  int size = self->head - self->base;
  var o;

  if (index >= size || index < 0)
    coal_throw(coal_new(coal_lang_IndexOutOfBoundsException(),
			"ArrayList_set: index out of bounds"));

  o = self->base[index];
  self->base[index] = elem;

  return o;
}

/* util.ArrayList methods */

/* ... */

SETUP_CLASS_DESCRIPTION(coal_util_ArrayList,
			coal_util_list(),
			LIBRARY_STR ".util.ArrayList",
			coal_util_AbstractList(),
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
			ArrayList_size,
			/* list */
			ArrayList_get,
			ArrayList_insert,
			ArrayList_set);

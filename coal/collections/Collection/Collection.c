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

#include <coal/private/library.h>
#include <coal/private/object_orientation.h>
#include <coal/private/virtual_methods.h>

#include <coal/base/Metaclass.h>

#include <coal/collections/Iterable.h>

#include <coal/collections/Collection.h>
#include <coal/collections/Collection/Collection.rep.h>

/* collections.Collection implements base.Object methods */
var Collection_constructor (var _self, va_list * args) {
  const class(Metaclass) * class;
  class(Collection) * self = _self;

  class = coal_collections_Collection();
  class->super->constructor(_self, args);

  OverrideMethod(self, args, add);
  OverrideMethod(self, args, clear);
  OverrideMethod(self, args, contains);
  OverrideMethod(self, args, isEmpty);
  OverrideMethod(self, args, remove);
  OverrideMethod(self, args, size);

  return _self;
}

/* selector functions */

bool coal_collections_Collection_add (var self, var element) {
  const class(Collection) * class;
  class = coal_base_Object_getClass(self);

  CheckAndThrowMissingMethod(class,
			     coal_collections_Collection());

  return class->add(self, element);
}

void coal_collections_Collection_clear (var self) {
  const class(Collection) * class;
  class = coal_base_Object_getClass(self);

  CheckAndThrowMissingMethod(class,
			     coal_collections_Collection());

  class->clear(self);
}

bool coal_collections_Collection_contains (val self, val element) {
  const class(Collection) * class;
  class = coal_base_Object_getClass(self);

  CheckAndThrowMissingMethod(class,
			     coal_collections_Collection());

  return class->contains(self, element);
}

bool coal_collections_Collection_isEmpty (val self) {
  const class(Collection) * class;
  class = coal_base_Object_getClass(self);

  CheckAndThrowMissingMethod(class,
			     coal_collections_Collection());

  return class->isEmpty(self);
}

bool coal_collections_Collection_remove (var self, val element) {
  const class(Collection) * class;
  class = coal_base_Object_getClass(self);

  CheckAndThrowMissingMethod(class,
			     coal_collections_Collection());

  return class->remove(self, element);
}

size_t coal_collections_Collection_size (val self) {
  const class(Collection) * class;
  class = coal_base_Object_getClass(self);

  CheckAndThrowMissingMethod(class,
			     coal_collections_Collection());

  return class->size(self);
}

SETUP_CLASS_DESCRIPTION(coal_collections_Collection,
			coal_base_Metaclass(),
			LIBRARY_PREFIX "collections" LIBRARY_MODSEP "Collection",
			coal_collections_Iterable(),
			sizeof(class(Collection)),
			/* Object */
			INHERIT_METHOD,         /* cmp */
			Collection_constructor,
			INHERIT_METHOD,         /* destructor */
			INHERIT_METHOD,         /* equals */
			INHERIT_METHOD,         /* hashCode */
			INHERIT_METHOD);        /* toString */

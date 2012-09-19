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

#include <coal/private/foreach.h>
#include <coal/private/library.h>
#include <coal/private/object_orientation.h>
#include <coal/private/virtual_methods.h>

#include <coal/abstract/Abstract.h>
#include <coal/collections/Collection.h>

#include <coal/collections/AbstractCollection.h>
#include <coal/collections/AbstractCollection/AbstractCollection.rep.h>

/* collections.AbstractCollection
   implements base.Object methods */

bool AbstractCollection_equals (val self, val other) {
  if (coal_collections_Collection_size(self) !=
      coal_collections_Collection_size(other))
    return false;

  coal_foreach (val elem, self) {
    if (! coal_collections_Collection_contains(other, elem))
      return false;
  } coal_foreach_end;

  return true;
}

size_t AbstractCollection_hashCode (val self) {
  size_t hash = 0;

  coal_foreach (val elem, self) {
    hash += coal_base_Object_hashCode(elem);
  } coal_foreach_end;

  return hash;
}

/* collections.AbstractCollection implements
   collections.Collection methods*/

bool AbstractCollection_contains (val self, val object) {
  coal_foreach (val elem, self) {
    if (coal_base_Object_equals(elem, object))
      return true;
  } coal_foreach_end;

  return false;
}

bool AbstractCollection_isEmpty (val self) {
  return coal_collections_Collection_size(self) == 0;
}

size_t AbstractCollection_size (val self) {
  size_t size = 0;

  coal_foreach (val e coal_attr_unused, self) {
    size += 1;
  } coal_foreach_end;

  return size;
}

SETUP_CLASS_DESCRIPTION(coal_collections_AbstractCollection,
			coal_collections_Collection(),
			LIBRARY_PREFIX "collections" LIBRARY_MODSEP "AbstractCollection",
			coal_abstract_Abstract(),
			sizeof(class(AbstractCollection)),
			/* Object */
			INHERIT_METHOD, /* cmp */
			INHERIT_METHOD, /* constructor */
			INHERIT_METHOD, /* destructor */
			AbstractCollection_equals,
			AbstractCollection_hashCode,
			INHERIT_METHOD, /* toString */
			/* Iterable */
			ABSTRACT_METHOD, /* iterator */
			/* Collection */
			ABSTRACT_METHOD, /* add */
			ABSTRACT_METHOD, /* clear */
			AbstractCollection_contains,
			AbstractCollection_isEmpty,
			ABSTRACT_METHOD, /* remove */
			AbstractCollection_size);

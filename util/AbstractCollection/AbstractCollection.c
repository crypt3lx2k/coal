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

#include <coal/lang/UnsupportedOperationException.h>

#include <coal/lang/abstract.h>
#include <coal/lang/iterable.h>

#include <coal/util/collection.h>
#include <coal/util/iterator.h>

#include <coal/util/AbstractCollection.h>
#include <coal/util/AbstractCollection/AbstractCollection.rep>

/* override lang.object methods */

bool AbstractCollection_equals (const var self, const var other) {
  if (coal_util_collection_size(self) !=
      coal_util_collection_size(other))
    return false;

  foreach (var elem, self) {
    if (! coal_util_collection_contains(other, elem))
      return false;
  } foreach_end;

  return true;
}

int AbstractCollection_hashCode (const var self) {
  int hash = 0;

  foreach (var elem, self) {
    hash += coal_lang_hashCode(elem);
  } foreach_end;

  return hash;
}

var AbstractCollection_toString (const var self) {
  var s = coal_new(coal_lang_string(), "[");
  var b = coal_lang_string_join(coal_new(coal_lang_string(), ", "), self);

  s = coal_lang_string_concat(s, b);

  return coal_lang_string_concat(s, coal_new(coal_lang_string(), "]"));
}

/* util.collection methods */

void AbstractCollection_unsupported (const var self) {
  const class(metaclass) * class = coal_lang_getClass(self);

  coal_throw(coal_new(coal_lang_UnsupportedOperationException(),
		      "%s does not support the attempted operation",
		      class->name));
}

bool AbstractCollection_contains (const var self, const var object) {
  foreach (var elem, self) {
    if (coal_lang_equals(elem, object))
      return true;
  } foreach_end;

  return false;
}

bool AbstractCollection_isEmpty (const var self) {
  return coal_util_collection_size(self) == 0;
}

int AbstractCollection_size (const var self) {
  int size = 0;

  foreach (var elem __attribute__ ((unused)), self) {
    size += 1;
  } foreach_end;

  return size;
}

SETUP_CLASS_DESCRIPTION(coal_util_AbstractCollection,
			coal_util_collection(),
			LIBRARY_STR ".util.AbstractCollection",
			coal_lang_abstract(),
			sizeof(class(AbstractCollection)),
			/* object */
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			AbstractCollection_equals,
			AbstractCollection_hashCode,
			AbstractCollection_toString,
			/* iterable */
			ABSTRACT_METHOD,
			/* collection */
			AbstractCollection_unsupported, /* add */
			AbstractCollection_unsupported, /* clear */
			AbstractCollection_contains,
			AbstractCollection_isEmpty,
			AbstractCollection_unsupported, /* remove */
			AbstractCollection_size);

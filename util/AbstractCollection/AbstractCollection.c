#include <coal/core/implementation.h>

#include <coal/lang/abstract.h>
#include <coal/util/collection.h>

#include <coal/util/AbstractCollection.h>

/* override lang.object methods */

bool AbstractCollection_equals (const var self, const var other) {
  if (coal_util_collection_size(self) !=
      coal_util_collection_size(other))
    return false;

  foreach(var elem, self) {
    if (! coal_util_collection_contains(other, elem))
      return false;
  } foreach_end;

  return true;
}

/* util.collection methods */

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
			0,
			/* object */
			AbstractCollection_equals,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			/* iterable */
			INHERIT_METHOD,
			/* collection */
			AbstractCollection_contains,
			AbstractCollection_isEmpty,
			AbstractCollection_size);

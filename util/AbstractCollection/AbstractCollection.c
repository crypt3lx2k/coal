#include <coal/core/implementation.h>

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
  var d = coal_new(coal_lang_string(), ", ");
  var e = coal_new(coal_lang_string(), "]");
  var i = coal_lang_iterable_iterator(self);

  while (coal_util_iterator_hasNext(i)) {
    var elem = coal_util_iterator_next(i);
    var t = coal_lang_toString(elem);

    s = coal_lang_string_concat(s, t);

    if (coal_util_iterator_hasNext(i))
      s = coal_lang_string_concat(s, d);

    coal_del(t);
  }

  s = coal_lang_string_concat(s, e);

  coal_del(i);
  coal_del(e);
  coal_del(d);

  return s;
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
			sizeof(class(AbstractCollection)),
			/* object */
			AbstractCollection_equals,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			AbstractCollection_hashCode,
			AbstractCollection_toString,
			/* iterable */
			ABSTRACT_METHOD,
			/* collection */
			ABSTRACT_METHOD, /* add */
			ABSTRACT_METHOD, /* clear */
			AbstractCollection_contains,
			AbstractCollection_isEmpty,
			ABSTRACT_METHOD, /* remove */
			AbstractCollection_size);

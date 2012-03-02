#include <coal/core/implementation.h>

#include <coal/lang/IndexOutOfBoundsException.h>

#include <coal/lang/iterable.h>
#include <coal/util/iterator.h>

#include <coal/util/AbstractCollection.h>
#include <coal/util/collection.h>
#include <coal/util/list.h>

#include <coal/util/AbstractList.h>
#include <coal/util/AbstractList/AbstractList.rep>

bool AbstractList_equals (const var self, const var other) {
  var i coal_local;

  if (coal_util_collection_size(self) !=
      coal_util_collection_size(other))
    return false;

  i = coal_lang_iterable_iterator(other);

  foreach (var elem, self) {
    var o = coal_util_iterator_next(i);

    if (! coal_lang_equals(elem, o))
      return false;
  } foreach_end;

  return true;
}

var AbstractList_get (const var self, int index) {
  var elem = NULL;

  foreach (elem, self) {
    if (! index--)
      break;
  } foreach_end;

  if (index)
    coal_throw(coal_new(coal_lang_IndexOutOfBoundsException(),
			"AbstractList_get: index out of bounds."));

  return elem;
}

SETUP_CLASS_DESCRIPTION(coal_util_AbstractList,
			coal_util_list(),
			LIBRARY_STR ".util.AbstractList",
			coal_util_AbstractCollection(),
			sizeof(class(AbstractList)),
			/* object */
			INHERIT_METHOD, /* cmp */
			INHERIT_METHOD, /* constructor */
			INHERIT_METHOD, /* destructor */
			AbstractList_equals,
			INHERIT_METHOD, /* hashCode */
			INHERIT_METHOD, /* toString */
			/* iterable */
			INHERIT_METHOD, /* iterator */
			/* collection */
			INHERIT_METHOD, /* add */
			INHERIT_METHOD, /* clear */
			INHERIT_METHOD, /* contains */
			INHERIT_METHOD, /* remove */
			INHERIT_METHOD, /* size */
			/* list */
			AbstractList_get,
			ABSTRACT_METHOD,  /* insert */
			ABSTRACT_METHOD); /* set */

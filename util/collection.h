#ifndef COAL_UTIL_COLLECTION_H__
#define COAL_UTIL_COLLECTION_H__

#include <coal/coal.h>

/**
 * coal_util_collection
 * Metaclass for collections.
 *
 * @extends coal_lang_iterable
 * @constructor takes 13
 * @param (const char *) name of class
 * @param (const class(metaclass) *) super class
 * @param (size_t) size of instances in bytes
 * @param (int (*cmp)(const var, const var)) pointer to comparison function
 * @param (var (*constructor)(var, va_list *)) pointer to constructor
 * @param (var (*destructor)(var)) pointer to destructor
 * @param (bool (*equals)(const var, const var)) pointer to equality function
 * @param (int (*hashCode)(const var)) pointer to hash function
 * @param (var (*toString)(const var)) pointer to string function
 * @param (var (*iterator)(const var)) pointer function that returns an iterator for the object
 * @param (bool (*contains)(const var, const var)) pointer to that specifies if an object is in the collection
 * @param (bool (*isEmpty)(const var)) pointer to function that specifies if the collection is empty
 * @param (int (*size)(const var)) pointer to function that returns the number of elements in the collection
 */
cfundecl__ (const var coal_util_collection (void))
  __attribute__ ((const));

/**
 * coal_util_collection_contains
 * Returns whether an object is contained
 * within a collection.
 *
 * @param  (const var) the collection in question
 * @param  (const var) the object to check for existence
 * @return (bool) true if the object is contained in the collection and false otherwise
 */
cfundecl__ (bool coal_util_collection_contains (const var self, const var object));

/**
 * coal_util_collection_isEmpty
 * Returns whether a collection is empty.
 *
 * @param  (const var) the collection in question
 * @return (bool) true if the collection is empty and false otherwise
 */
cfundecl__ (bool coal_util_collection_isEmpty (const var self));

/**
 * coal_util_collection_size
 * Returns the number of elements in a collection.
 *
 * @param  (const var) the collection in question
 * @return (int) number of elements in the collection
 */
cfundecl__ (int coal_util_collection_size (const var self));

#ifdef UTIL_NAMESPACE_POLLUTE
# define collection          coal_util_collection
# define collection_contains coal_util_collection_contains
# define collection_isEmpty  coal_util_collection_isEmpty
# define collection_size     coal_util_collection_size
#endif

#ifdef COLLECTION_NAMESPACE_POLLUTE
# define contains coal_util_collection_contains
# define isEmpty  coal_util_collection_isEmpty
# define size     coal_util_collection_size
#endif

#endif /* COAL_UTIL_COLLECTION_H__ */

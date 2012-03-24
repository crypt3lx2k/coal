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

#ifndef COAL_UTIL_COLLECTION_H__
#define COAL_UTIL_COLLECTION_H__

#include <coal/coal.h>

/**
 * coal_util_collection
 * Metaclass for collections.
 *
 * @extends coal_lang_iterable
 * @constructor takes 16 arguments
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
 * @param (bool (*add)(var, var) pointer to function that adds element to the collection
 * @param (void (*clear)(var)) pointer to function that clears the collection
 * @param (bool (*contains)(const var, var)) pointer to that specifies if an object is in the collection
 * @param (bool (*isEmpty)(const var)) pointer to function that specifies if the collection is empty
 * @param (bool (*remove)(var, var)) pointer to function that removes element from the collection
 * @param (int (*size)(const var)) pointer to function that returns the number of elements in the collection
 */
cfundecl__ (const var coal_util_collection (void))
  __attribute__ ((const));

/**
 * coal_util_collection_add
 * Adds an element to the collection.
 *
 * @param  (var) the collection in question
 * @param  (var) the object to add
 * @return (bool) true if the collection was altered and false otherwise
 */
cfundecl__ (bool coal_util_collection_add (var self, var object));

/**
 * coal_util_collection_clear
 * Empties the collection.
 *
 * @param (var) the collection to empty
 */
cfundecl__ (void coal_util_collection_clear (var self));

/**
 * coal_util_collection_contains
 * Returns whether an object is contained
 * within a collection.
 *
 * @param  (const var) the collection in question
 * @param  (const var) the object to check for existence
 * @return (bool) true if the object is contained in the collection and false otherwise
 */
cfundecl__ (bool coal_util_collection_contains (const var self, var object));

/**
 * coal_util_collection_isEmpty
 * Returns whether a collection is empty.
 *
 * @param  (const var) the collection in question
 * @return (bool) true if the collection is empty and false otherwise
 */
cfundecl__ (bool coal_util_collection_isEmpty (const var self));

/**
 * coal_util_collection_remove
 * Removes element from collection.
 *
 * @param  (var) the collection in question
 * @param  (const var) the element to remove from the collection
 * @return (bool) true if the collection was altered and false otherwise
 */
cfundecl__ (bool coal_util_collection_remove (var self, var object));

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
# define collection_add      coal_util_collection_add
# define collection_clear    coal_util_collection_clear
# define collection_contains coal_util_collection_contains
# define collection_isEmpty  coal_util_collection_isEmpty
# define collection_remove   coal_util_collection_remove
# define collection_size     coal_util_collection_size
#endif

#ifdef COLLECTION_NAMESPACE_POLLUTE
# define add      coal_util_collection_add
# define clear    coal_util_collection_clear
# define contains coal_util_collection_contains
# define isEmpty  coal_util_collection_isEmpty
# define remove   coal_util_collection_remove
# define size     coal_util_collection_size
#endif

#endif /* COAL_UTIL_COLLECTION_H__ */

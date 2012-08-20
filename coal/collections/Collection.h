#ifndef COAL_COLLECTIONS_COLLECTION_H
#define COAL_COLLECTIONS_COLLECTION_H

#include <stddef.h> /* size_t */

#include <coal/collections/Iterable.h>

/**
 * coal_collections_Collection
 *
 * Metaclass for collections.
 *
 * @extends coal_collections_Iterable
 * @constructor takes 16 arguments
 * @param (const char *) name of class
 * @param (const class(Metaclass) *) super class
 * @param (size_t) size of instances of this class in bytes
 * @param (int (*cmp)(val, val)) pointer to comparator function
 * @param (var (*constructor)(var, va_list *)) pointer to constructor
 * @param (var (*destructor)(var)) pointer to destructor
 * @param (bool (*equals)(val, val)) pointer to equality function
 * @param (int (*hashCode)(val)) pointer to hash function
 * @param (var (*toString)(val)) pointer to string representation function
 * @param (var (*iterator)(val)) pointer to function that returns iterator for the object
 * @param (bool (*add)(var, var)) pointer to function that adds element to collection
 * @param (void (*clear)(var)) pointer to function that clears the collection
 * @param (bool (*contains)(val, val)) pointer to function that specifies if an element is in the collection
 * @param (bool (*isEmpty)(val)) pointer to function that specifies if the collection is empty
 * @param (bool (*remove)(var, val)) pointer to function that removes element from the collection
 * @param (size_t (*size)(val)) pointer to function that returns the number of elements in the collection
 */
coal_cfunspec val coal_collections_Collection (void) coal_funattr_const;

/**
 * coal_collections_Collection_add
 *
 * Adds an element to the collection.
 *
 * This function returns true if the collection was modified
 * due to this call and false otherwise.
 *
 * The collection will eat the reference to the element, if
 * you want to keep using an object after adding it to an
 * collection you must call coal_acquire() on it.
 *
 * @param  (var) collection to add element to
 * @param  (var) element to add to the collection
 * @return (bool) true if collection was modified and false otherwise
 */
coal_cfunspec bool coal_collections_Collection_add (var self, var element);

/**
 * coal_collections_Collection_clear
 *
 * Empties the collection.
 *
 * @param  (var) the collection to empty
 */
coal_cfunspec void coal_collections_Collection_clear (var self);

/**
 * coal_collections_Collection_contains
 *
 * Returns whether an object is contained in the collection.
 *
 * @param  (val) the collection we search through
 * @param  (val) the element to search for
 * @return (bool) true if element was found and false otherwise
 */
coal_cfunspec bool coal_collections_Collection_contains (val self, val element);

/**
 * coal_collections_Collection_isEmpty
 *
 * Returns whether collection is empty.
 *
 * @param  (val) the collection to check for emptiness
 * @return (bool) true if the collection is empty and false otherwise
 */
coal_cfunspec bool coal_collections_Collection_isEmpty (val self);

/**
 * coal_collections_Collection_remove
 *
 * Removes element from collection.
 *
 * This function returns true if the collection was modified
 * due to this call and false otherwise.
 *
 * @param  (var) collection to remove element from
 * @param  (val) element to remove from collection
 * @return (bool) true if collection was modified and false otherwise
 */
coal_cfunspec bool coal_collections_Collection_remove (var self, val element);

/**
 * coal_collections_Collection_size
 *
 * Returns the number of elements in the collection.
 *
 * @param  (val) collection to count elements of
 * @return (size_t) number of elements in the collection
 */
coal_cfunspec size_t coal_collections_Collection_size (val self);

#ifdef COAL_COLLECTIONS_NAMESPACE_POLLUTE
# define Collection()              coal_collections_Collection()
# define Collection_add(s, e)      coal_collections_Collection_add(s, e)
# define Collection_clear(s)       coal_collections_Collection_clear(s)
# define Collection_contains(s, e) coal_collections_Collection_contains(s, e)
# define Collection_isEmpty(s)     coal_collections_Collection_isEmpty(s)
# define Collection_remove(s, e)   coal_collections_Collection_remove(s, e)
# define Collection_size(s)        coal_collections_Collection_size(s)
#endif

#ifdef COAL_COLLECTIONS_COLLECTION_NAMESPACE_POLLUTE
# define add(s, e)      coal_collections_Collection_add(s, e)
# define clear(s)       coal_collections_Collection_clear(s)
# define contains(s, e) coal_collections_Collection_contains(s, e)
# define isEmpty(s)     coal_collections_Collection_isEmpty(s)
# define remove(s, e)   coal_collections_Collection_remove(s, e)
# define size(s)        coal_collections_Collection_size(s)
#endif

#endif /* COAL_COLLECTIONS_COLLECTION_H */

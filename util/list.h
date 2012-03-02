#ifndef COAL_UTIL_LIST_H__
#define COAL_UTIL_LIST_H__

#include <coal/coal.h>

/**
 * coal_util_list
 * Metaclass for lists.
 *
 * @extends coal_util_collection
 * @constructor takes 19 arguments
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
 * @param (var (*get)(const var, int)) pointer to function that fetches element on specified position
 * @param (bool (*insert)(var, int, var) pointer to function that inserts element at specified position
 * @param (var (*set)(var, int, var)) pointer to function that sets element at specified position
 */
cfundecl__ (const var coal_util_list (void))
  __attribute__ ((const));

/**
 * coal_util_list_get
 * Returns element at specified position in list.
 *
 * @param  (const var) list in question
 * @param  (int) index of element
 * @return (var) element at index in list
 */
cfundecl__ (var coal_util_list_get (const var self, int index));

/**
 * coal_util_list_insert
 * Inserts element into list at specified position.
 *
 * @param  (var) list in question
 * @param  (int) index of new element in list
 * @param  (var) element to insert
 * @return (bool) true if the list was altered and false otherwise
 */
cfundecl__ (bool coal_util_list_insert (var self, int index, var elem));

/**
 * coal_util_list_set
 * Sets element in list at specified position
 * overwriting old element.
 *
 * @param  (var) list in question
 * @param  (int) index of new element in list
 * @param  (var) element to overwrite with
 * @return (var) old element at specified position
 */
cfundecl__ (var coal_util_list_set (var self, int index, var elem));

#ifdef UTIL_NAMESPACE_POLLUTE
# define list        coal_util_list
# define list_get    coal_util_list_get
# define list_insert coal_util_list_insert
# define list_set    coal_util_list_set
#endif

#ifdef LIST_NAMESPACE_POLLUTE
# define get    coal_util_list_get
# define insert coal_util_list_insert
# define set    coal_util_lis_set
#endif

#endif /* COAL_UTIL_LIST_H__ */

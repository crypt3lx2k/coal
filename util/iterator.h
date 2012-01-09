#ifndef COAL_UTIL_ITERATOR_H__
#define COAL_UTIL_ITERATOR_H__

#include <coal/coal.h>

/**
 * coal_util_iterator
 * Metaclass for iterators.
 *
 * @extends coal_lang_metaclass
 * @constructor takes 11 arguments
 * @param (const char *) name of class
 * @param (const class(metaclass) *) super class
 * @param (size_t) size of instances in bytes
 * @param (int (*cmp)(const var, const var)) pointer to comparison function
 * @param (var (*constructor)(var, va_list *)) pointer to constructor
 * @param (var (*destructor)(var)) pointer to destructor
 * @param (bool (*equals)(const var, const var)) pointer to equality function
 * @param (int (*hashCode)(const var)) pointer to hash function
 * @param (var (*toString)(const var)) pointer to string function
 * @param (bool (*hasNext)(const var)) pointer to function which returns whether the iterator has more elements
 * @param (var (*next)(var)) pointer to function which returns the next element
 */
cfundecl__ (const var coal_util_iterator (void))
  __attribute__ ((const));

/**
 * coal_util_iterator_hasNext
 * Returns whether the iterator has more
 * elements to iterate over or not.
 *
 * @param  (const var) the iterator in question
 * @return (bool) true if there are more elements
 */
cfundecl__ (bool coal_util_iterator_hasNext (const var self));

/**
 * coal_util_iterator_next
 * Returns the next element in the iteration.
 *
 * @param  (var) the iterator in question
 * @return (var) the next element in the iteration
 */
cfundecl__ (var coal_util_iterator_next (var self));

#ifdef UTIL_NAMESPACE_POLLUTE
# define iterator         coal_util_iterator
# define iterator_hasNext coal_util_iterator_hasNext
# define iterator_next    coal_util_iterator_next
#endif

#ifdef ITERATOR_NAMESPACE_POLLUTE
# define hasNext coal_util_iterator_hasNext
# define next    coal_util_iterator_next
#endif

#endif /* COAL_UTIL_ITERATOR_H__ */
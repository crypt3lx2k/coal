#ifndef COAL_UTIL_ARRAYLIST_H__
#define COAL_UTIL_ARRAYLIST_H__

#include <coal/coal.h>

/**
 * coal_util_ArrayList
 * A list implemented with a dynamic array.
 *
 * @extends coal_util_AbstractList
 * @constructor takes 2 arguments
 * @param (size_t) the number of elements to pre-allocate space for
 * @param (float) the resize factor of the underlying array
 */
cfundecl__ (const var coal_util_ArrayList (void))
  __attribute__ ((const));

#ifdef UTIL_NAMESPACE_POLLUTE
# define ArrayList coal_util_ArrayList
#endif

#endif /* COAL_UTIL_ARRAYLIST_H__ */

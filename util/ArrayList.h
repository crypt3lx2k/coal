#ifndef COAL_UTIL_ARRAYLIST_H__
#define COAL_UTIL_ARRAYLIST_H__

#include <coal/coal.h>

/**
 * coal_util_ArrayList
 * A list implemented with a dynamic array.
 *
 * @extends coal_lang_object
 * @constructor takes 1 argument
 * @param (size_t) the number of elements to pre-allocate space for
 */
cfundecl__ (const var coal_util_ArrayList (void))
  __attribute__ ((const));

#ifdef UTIL_NAMESPACE_POLLUTE
# define ArrayList coal_util_ArrayList
#endif

#endif /* COAL_UTIL_ARRAYLIST_H__ */

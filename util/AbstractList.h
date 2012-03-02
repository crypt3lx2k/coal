#ifndef COAL_UTIL_ABSTRACTLIST_H__
#define COAL_UTIL_ABSTRACTLIST_H__

#include <coal/coal.h>

/**
 * coal_util_AbstractList
 * Abstract base class for lists.
 * Subclasses must only implement an iterator
 * and the destructive operations.
 *
 * @extends coal_util_AbstractCollection
 * @constructor takes 0 arguments
 */
cfundecl__ (const var coal_util_AbstractList (void))
  __attribute__ ((const));

#ifdef UTIL_NAMESPACE_POLLUTE
# define AbstractList coal_util_AbstractList
#endif

#endif /* COAL_UTIL_ABSTRACTLIST_H__ */

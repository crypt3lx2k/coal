#ifndef COAL_UTIL_ABSTRACTCOLLECTION_H__
#define COAL_UTIL_ABSTRACTCOLLECTION_H__

#include <coal/coal.h>

/**
 * coal_util_AbstractCollection
 * Abstract base class for collections.
 * Subclasses need only implement an iterator
 * and the destructive operations.
 *
 * @extends coal_lang_abstract
 * @constructor takes 0 arguments
 */
cfundecl__ (const var coal_util_AbstractCollection (void))
  __attribute__ ((const));

#ifdef UTIL_NAMESPACE_POLLUTE
# define AbstractCollection coal_util_AbstractCollection
#endif

#endif /* COAL_UTIL_ABSTRACTCOLLECTION_H__ */

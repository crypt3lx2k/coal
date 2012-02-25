#ifndef COAL_LANG_ABSTRACTINSTANTIATIONERROR_H__
#define COAL_LANG_ABSTRACTINSTANTIATIONERROR_H__

#include <coal/coal.h>

/**
 * coal_lang_AbstractInstantiationError
 * Error that indicates that an attempt was
 * made to instantiate an abstract class.
 *
 * @extends coal_lang_Error
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_AbstractInstantiationError (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define AbstractInstantiationError coal_lang_AbstractInstantiationError
#endif

#endif /* COAL_LANG_ABSTRACTINSTANTIATIONERROR_H__ */

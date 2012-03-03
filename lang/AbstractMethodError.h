#ifndef COAL_LANG_ABSTRACTMETHODERROR_H__
#define COAL_LANG_ABSTRACTMETHODERROR_H__

#include <coal/coal.h>

/**
 * coal_lang_AbstractMethodError
 * Error that indicates that a method
 * inherited from an abstract class was called.
 *
 * @extends coal_lang_AbstractError
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_AbstractMethodError (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define AbstractMethodError coal_lang_AbstractMethodError
#endif

#endif /* COAL_LANG_ABSTRACTMETHODERROR_H__ */

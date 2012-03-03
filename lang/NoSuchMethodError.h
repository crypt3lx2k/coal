#ifndef COAL_LANG_NOSUCHMETHODERROR_H__
#define COAL_LANG_NOSUCHMETHODERROR_H__

#include <coal/coal.h>

/**
 * coal_lang_NoSuchMethodError
 * Error that is thrown whenever
 * a method is invoked on an object
 * that does not contain the method.
 *
 * @extends coal_lang_Error
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_NoSuchMethodError (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define NoSuchMethodError coal_lang_NoSuchMethodError
#endif

#endif /* COAL_LANG_NOSUCHMETHODERROR_H__ */

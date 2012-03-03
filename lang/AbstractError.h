#ifndef COAL_LANG_ABSTRACTERROR_H__
#define COAL_LANG_ABSTRACTERROR_H__

#include <coal/coal.h>

/**
 * coal_lang_AbstractError
 * Error that indicates that a request
 * was made to an abstract class.
 *
 * @extends coal_lang_Error
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_AbstractError (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define AbstractError coal_lang_AbstractError
#endif

#endif /* COAL_LANG_ABSTRACTERROR_H__ */

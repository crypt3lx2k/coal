#ifndef COAL_LANG_THROWABLE_H__
#define COAL_LANG_THROWABLE_H__

#include <coal/coal.h>

/**
 * coal_lang_throwable
 * Base class for exceptions and errors.
 *
 * @extends coal_lang_object
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_throwable (void))
  __attribute__ ((const));

/**
 * coal_lang_throwable_getMessage
 * Returns the underlying message of a throwable
 * as an immutable char array.
 *
 * @param  (const var) throwable in question
 * @return (const char *) message of throwable
 */
cfundecl__ (const char * coal_lang_throwable_getMessage (const var self));

#ifdef LANG_NAMESPACE_POLLUTE
# define throwable coal_lang_throwable
# define throwable_getMessage coal_lang_throwable_getMessage
#endif

#ifdef THROWABLE_NAMESPACE_POLLUTE
# define getMessage coal_lang_throwable_getMessage
#endif

#endif /* COAL_LANG_THROWABLE_H__ */

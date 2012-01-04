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
cfundecl__ (const var coal_lang_throwable (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define throwable coal_lang_throwable
#endif

#endif /* COAL_LANG_THROWABLE_H__ */

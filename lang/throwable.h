#ifndef COAL_LANG_THROWABLE_H__
#define COAL_LANG_THROWABLE_H__

#include <coal/coal.h>
#include <coal/lang/namespace.h>

/**
 * lang(throwable)
 * Base class for exceptions and errors.
 *
 * @extends lang(object)
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (type) printf-like arguments
 */
cfundecl__ (const var lang(throwable) (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define throwable lang(throwable)
#endif

#endif /* COAL_LANG_THROWABLE_H__ */

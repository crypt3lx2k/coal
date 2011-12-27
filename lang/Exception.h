#ifndef COAL_LANG_EXCEPTION_H__
#define COAL_LANG_EXCEPTION_H__

#include <coal/coal.h>
#include <coal/lang/namespace.h>

/**
 * lang(Exception)
 * Base class for throwables that
 * a reasonable application might
 * want to catch.
 *
 * @extends lang(throwable)
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (type) printf-like arguments
 */
cfundecl__ (const var lang(Exception) (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define Exception lang(Exception)
#endif

#endif /* COAL_LANG_EXCEPTION_H__ */

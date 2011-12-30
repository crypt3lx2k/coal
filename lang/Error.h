#ifndef COAL_LANG_ERROR_H__
#define COAL_LANG_ERROR_H__

#include <coal/coal.h>
#include <coal/lang/namespace.h>

/**
 * lang(Error)
 * Base class for throwables that
 * a reasonable application might
 * NOT want to catch.
 *
 * @extends lang(throwable)
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var lang(Error) (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define Error lang(Error)
#endif

#endif /* COAL_LANG_ERROR_H__ */

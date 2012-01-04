#ifndef COAL_LANG_ERROR_H__
#define COAL_LANG_ERROR_H__

#include <coal/coal.h>

/**
 * coal_lang_Error
 * Base class for throwables that
 * a reasonable application might
 * NOT want to catch.
 *
 * @extends coal_lang_throwable
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_Error (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define Error coal_lang_Error
#endif

#endif /* COAL_LANG_ERROR_H__ */

#ifndef COAL_LANG_EXCEPTION_H__
#define COAL_LANG_EXCEPTION_H__

#include <coal/coal.h>

/**
 * coal_lang_Exception
 * Base class for throwables that
 * a reasonable application might
 * want to catch.
 *
 * @extends coal_lang_throwable
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_Exception (void)) 
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define Exception coal_lang_Exception
#endif

#endif /* COAL_LANG_EXCEPTION_H__ */

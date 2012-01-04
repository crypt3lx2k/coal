#ifndef COAL_LANG_NULLPOINTEREXCEPTION_H__
#define COAL_LANG_NULLPOINTEREXCEPTION_H__

#include <coal/coal.h>

/**
 * coal_lang_NullPointerException
 * Exception that indicates attempted
 * dereference of a null pointer.
 *
 * @extends coal_lang_Exception
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_NullPointerException (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define NullPointerException coal_lang_NullPointerException
#endif

#endif /* COAL_LANG_NULLPOINTEREXCEPTION_H__ */

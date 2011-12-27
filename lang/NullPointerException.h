#ifndef COAL_LANG_NULLPOINTEREXCEPTION_H__
#define COAL_LANG_NULLPOINTEREXCEPTION_H__

#include <coal/coal.h>
#include <coal/lang/namespace.h>

/**
 * lang(NullPointerException)
 * Exception that indicates attempted
 * dereference of a null pointer.
 *
 * @extends lang(Exception)
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (type) printf-like arguments
 */
cfundecl__ (const var lang(NullPointerException) (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define NullPointerException lang(NullPointerException)
#endif

#endif /* COAL_LANG_NULLPOINTEREXCEPTION_H__ */

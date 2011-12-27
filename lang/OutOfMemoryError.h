#ifndef COAL_LANG_OUTOFMEMORYERROR_H__
#define COAL_LANG_OUTOFMEMORYERROR_H__

#include <coal/coal.h>
#include <coal/lang/namespace.h>

/**
 * lang(OutOfMemoryError)
 * Error that indicates that a
 * failed memory request was made.
 *
 * @extends lang(Error)
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (type) printf-like arguments
 */
cfundecl__ (const var lang(OutOfMemoryError) (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define OutOfMemoryError lang(OutOfMemoryError)
#endif

#endif /* COAL_LANG_OUTOFMEMORYERROR_H__ */

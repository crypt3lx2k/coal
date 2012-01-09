#ifndef COAL_LANG_OUTOFMEMORYERROR_H__
#define COAL_LANG_OUTOFMEMORYERROR_H__

#include <coal/coal.h>

/**
 * coal_lang_OutOfMemoryError
 * Error that indicates that a
 * failed memory request was made.
 *
 * @extends coal_lang_Error
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_OutOfMemoryError (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define OutOfMemoryError coal_lang_OutOfMemoryError
#endif

#endif /* COAL_LANG_OUTOFMEMORYERROR_H__ */

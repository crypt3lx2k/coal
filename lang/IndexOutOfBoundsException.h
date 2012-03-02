#ifndef COAL_LANG_INDEXOUTOFBOUNDSEXCEPTION_H__
#define COAL_LANG_INDEXOUTOFBOUNDSEXCEPTION_H__

#include <coal/coal.h>

/**
 * coal_lang_IndexOutOfBoundsException
 * Exception that indicates that an attempt
 * was made to step out of bounds of an ordered
 * collection, like an array, a vector or a list.
 *
 * @extends coal_lang_Exception
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_IndexOutOfBoundsException (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define IndexOutOfBoundsException coal_lang_IndexOutOfBoundsException
#endif

#endif /* COAL_LANG_INDEXOUTOFBOUNDSEXCEPTION_H__ */

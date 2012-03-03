#ifndef COAL_LANG_UNSUPPORTEDOPERATIONEXCEPTION_H__
#define COAL_LANG_UNSUPPORTEDOPERATIONEXCEPTION_H__

#include <coal/coal.h>

/**
 * coal_lang_UnsupportedOperationException
 * Exception that indicates that a call
 * was made to an optional operation
 * that is not implemented.
 *
 * @extends coal_lang_Exception
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_UnsupportedOperationException (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define UnsupportedOperationException coal_lang_UnsupportedOperationException
#endif

#endif /* COAL_LANG_UNSUPPORTEDOPERATIONEXCEPTION_H__ */

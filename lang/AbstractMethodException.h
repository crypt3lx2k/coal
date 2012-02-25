#ifndef COAL_LANG_ABSTRACTMETHODEXCEPTION_H__
#define COAL_LANG_ABSTRACTMETHODEXCEPTION_H__

#include <coal/coal.h>

/**
 * coal_lang_AbstractMethodException
 * Exception that indicates that a method
 * inherited from an abstract class was called.
 *
 * @extends coal_lang_Exception
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_AbstractMethodException (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define AbstractMethodException coal_lang_AbstractMethodException
#endif

#endif /* COAL_LANG_ABSTRACTMETHODEXCEPTION_H__ */

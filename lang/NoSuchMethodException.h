#ifndef COAL_LANG_NOSUCHMETHODEXCEPTION_H__
#define COAL_LANG_NOSUCHMETHODEXCEPTION_H__

#include <coal/coal.h>

/**
 * coal_lang_NoSuchMethodException
 * Exception that is thrown whenever
 * a method is invoked on an object
 * that does not contain the method.
 *
 * @extends coal_lang_Exception
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_NoSuchMethodException (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define NoSuchMethodException coal_lang_NoSuchMethodException
#endif

#endif /* COAL_LANG_NOSUCHMETHODEXCEPTION_H__ */

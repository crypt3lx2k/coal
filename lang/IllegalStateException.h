#ifndef COAL_LANG_ILLEGALSTATEEXCEPTION_H__
#define COAL_LANG_ILLEGALSTATEEXCEPTION_H__

#include <coal/coal.h>

/* this is hardly better than an
   `SomethingWentWrongException' */
/**
 * coal_lang_IllegalStateException
 * Exception that indicates that an alteration
 * to an object would cause its state to be
 * invalid or illegal.
 *
 * @extends coal_lang_Exception
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_IllegalStateException (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define IllegalStateException coal_lang_IllegalStateException
#endif

#endif /* COAL_LANG_ILLEGALSTATEEXCEPTION_H__ */

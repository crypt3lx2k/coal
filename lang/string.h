#ifndef COAL_LANG_STRING_H__
#define COAL_LANG_STRING_H__

#include <coal/coal.h>
#include <coal/core/namespaces.h>
#include <coal/lang/namespace.h>

#define lang_string(identifier) \
  lang(namespace(string, identifier))

/**
 * lang(string)
 * Class that represents a sequence
 * of characters.
 *
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (type) printf-like arguments
 */
cfundecl__ (const var lang(string) (void));

/**
 * string(chars)
 * Returns the underlying string
 * as an immutable character array.
 *
 * @param  (const var) string object
 * @return (const char *) characters of string
 */
cfundecl__ (const char * lang_string(chars) (const var self));

#ifdef LANG_NAMESPACE_POLLUTE
# define string lang(string)
#endif

#ifdef LANG_STRING_NAMESPACE_POLLUTE
# define chars lang_string(chars)
#endif

#endif /* COAL_LANG_STRING_H__ */

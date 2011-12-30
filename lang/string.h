#ifndef COAL_LANG_STRING_H__
#define COAL_LANG_STRING_H__

#include <coal/coal.h>
#include <coal/lang/namespace.h>

/**
 * lang(string)
 * Class that represents a mutable
 * sequence of characters.
 *
 * @extends lang(object)
 * @constructor takes 2 arguments
 * @param (const char *) string
 * @param (int) size of string
 */
cfundecl__ (const var lang(string) (void));

/**
 * lang_string(chars)
 * Returns the underlying string
 * as an immutable character array.
 *
 * @param  (const var) string object
 * @return (const char *) characters of string
 */
cfundecl__ (const char * lang(string_chars) (const var self));

/**
 * lang_string(concat)
 * Concatenates two strings, returns
 * a new string that has to be del'd.
 *
 * @param  (const var) first string
 * @param  (const var) second string
 * @return (var) concatenated string
 */
cfundecl__ (var lang(string_concat) (const var self, const var other));

/**
 * lang_string(length)
 * Returns the length of the string.
 *
 * @param  (const var) string
 * @return (size_t) length of string
 */
cfundecl__ (size_t lang(string_length) (const var self));

#ifdef LANG_NAMESPACE_POLLUTE
# define string        lang(string)
# define string_chars  lang(string_chars)
# define string_concat lang(string_concat)
# define string_length lang(string_length)
#endif

#endif /* COAL_LANG_STRING_H__ */

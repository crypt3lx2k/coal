#ifndef COAL_LANG_STRING_H__
#define COAL_LANG_STRING_H__

#include <coal/coal.h>

/**
 * coal_lang_string
 * Class that represents a
 * sequence of characters.
 *
 * @extends coal_lang_object
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_string (void));

/**
 * coal_lang_string_chars
 * Returns the underlying string
 * as an immutable character array.
 *
 * @param  (const var) string object
 * @return (const char *) characters of string
 */
cfundecl__ (const char * coal_lang_string_chars (const var self));

/**
 * coal_lang_string_concat
 * Concatenates two strings, returns
 * a new string that has to be del'd.
 *
 * @param  (const var) first string
 * @param  (const var) second string
 * @return (var) concatenated string
 */
cfundecl__ (var coal_lang_string_concat (const var self, const var other));

/**
 * coal_lang_string_length
 * Returns the length of the string.
 *
 * @param  (const var) string
 * @return (size_t) length of string
 */
cfundecl__ (size_t coal_lang_string_length (const var self));

#ifdef LANG_NAMESPACE_POLLUTE
# define string        coal_lang_string
# define string_chars  coal_lang_string_chars
# define string_concat coal_lang_string_concat
# define string_length coal_lang_string_length
#endif

#endif /* COAL_LANG_STRING_H__ */

/*
 * coal - An object oriented general purpose library for GNU-C
 * Copyright (C) 2012 Truls Edvard Stokke
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

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
cfundecl__ (const var coal_lang_string (void))
  __attribute__ ((const));

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
 * Concatenates two strings.
 *
 * @param  (var) first string
 * @param  (var) second string
 * @return (var) concatenated string
 */
cfundecl__ (var coal_lang_string_concat (var self, var other));

/**
 * coal_lang_string_join
 * Uses string as a delimiter to join together an iterable.
 *
 * @param  (const var) the delimiter
 * @param  (const var) iterable to join with delimiter
 * @return (var) the resulting string
 */
cfundecl__ (var coal_lang_string_join (var self, const var iterable));

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
# define string_join   coal_lang_string_join
# define string_length coal_lang_string_length
#endif

#ifdef STRING_NAMESPACE_POLLUTE
# define chars  coal_lang_string_chars
# define concat coal_lang_string_concat
# define join   coal_lang_string_join
# define length coal_lang_string_length
#endif

#endif /* COAL_LANG_STRING_H__ */

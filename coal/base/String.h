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

#ifndef COAL_BASE_STRING_H
#define COAL_BASE_STRING_H

#include <coal/base/Object.h>

/**
 * coal_base_String
 *
 * Class that.rep.hresents an immutable sequence of characters.
 *
 * @extends coal_base_Object
 * @constructor takes 2 arguments
 * @param (const char *) pointer to string
 * @param (size_t) size of string or 0 if it is unknown
 */
coal_cfunspec val coal_base_String (void) coal_funattr_const;

/**
 * coal_base_String_format
 *
 * This static method creates a String from printf-like format
 * and arguments.
 *
 * @static
 * @param  (const char *) printf-like format string
 * @param  (...) printf-like format arguments
 */
coal_cfunspec var coal_base_String_format (const char * fmt, ...);

#ifdef COAL_BASE_NAMESPACE_POLLUTE
# define String()                coal_base_String()
# define String_format(fmt, ...) coal_base_String_format(fmt, __VA_ARGS__)
#endif

#ifdef COAL_BASE_STRING_NAMESPACE_POLLUTE
# define format(fmt, ...) coal_base_String_format(fmt, __VA_ARGS__)
#endif

#endif /* COAL_BASE_STRING_H */

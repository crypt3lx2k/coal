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

#ifndef COAL_LANG_THROWABLE_H__
#define COAL_LANG_THROWABLE_H__

#include <coal/coal.h>

/**
 * coal_lang_throwable
 * Base class for exceptions and errors.
 *
 * @extends coal_lang_object
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
cfundecl__ (const var coal_lang_throwable (void))
  __attribute__ ((const));

/**
 * coal_lang_throwable_getMessage
 * Returns the underlying message of a throwable
 * as an immutable char array.
 *
 * @param  (const var) throwable in question
 * @return (const char *) message of throwable
 */
cfundecl__ (const char * coal_lang_throwable_getMessage (const var self));

#ifdef LANG_NAMESPACE_POLLUTE
# define throwable coal_lang_throwable
# define throwable_getMessage coal_lang_throwable_getMessage
#endif

#ifdef THROWABLE_NAMESPACE_POLLUTE
# define getMessage coal_lang_throwable_getMessage
#endif

#endif /* COAL_LANG_THROWABLE_H__ */

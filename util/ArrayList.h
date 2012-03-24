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

#ifndef COAL_UTIL_ARRAYLIST_H__
#define COAL_UTIL_ARRAYLIST_H__

#include <coal/coal.h>

/**
 * coal_util_ArrayList
 * A list implemented with a dynamic array.
 *
 * @extends coal_util_AbstractList
 * @constructor takes 2 arguments
 * @param (size_t) the number of elements to pre-allocate space for
 * @param (float) the resize factor of the underlying array
 */
cfundecl__ (const var coal_util_ArrayList (void))
  __attribute__ ((const));

#ifdef UTIL_NAMESPACE_POLLUTE
# define ArrayList coal_util_ArrayList
#endif

#endif /* COAL_UTIL_ARRAYLIST_H__ */

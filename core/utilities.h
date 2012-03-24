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

#ifndef COAL_CORE_UTILITIES_H__
#define COAL_CORE_UTILITIES_H__

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/utilities.h> directly; use <coal/core/implementation.h> instead."
#endif

/**
 * MAX
 * Returns the greater of
 * two primitive values.
 *
 * @param  (type) first value to compare
 * @param  (type) second value to compare
 * @return (type) greatest value
 */
#define MAX(a, b)                               \
  ({                                            \
    typeof(a) a__ = (a);                        \
    typeof(b) b__ = (b);                        \
                                                \
    a__ < b__ ? b__ : a__;                      \
  })

/**
 * MIN
 * Returns the lesser of
 * two primitive values.
 *
 * @param  (type) first value to compare
 * @param  (type) second value to compare
 * @return (type) lesser value
 */
#define MIN(a, b)                               \
  ({                                            \
    typeof(a) a__ = (a);                        \
    typeof(b) b__ = (b);                        \
                                                \
    a__ < b__ ? a__ : b__;                      \
  })

#endif /* COAL_CORE_UTIL_H__ */

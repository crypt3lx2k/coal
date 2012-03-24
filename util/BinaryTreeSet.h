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

#ifndef COAL_UTIL_BINARYTREESET_H__
#define COAL_UTIL_BINARYTREESET_H__

#include <coal/coal.h>

/**
 * coal_util_BinaryTreeSet
 * A set implemented as a binary tree.
 *
 * @extends coal_util_AbstractCollection
 * @constructor takes 0 arguments
 */
cfundecl__ (const var coal_util_BinaryTreeSet (void))
  __attribute__ ((const));

#ifdef UTIL_NAMESPACE_POLLUTE
# define BinaryTreeSet coal_util_BinaryTreeSet
#endif

#endif /* COAL_UTIL_BINARYTREESET_H__ */

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

#ifndef COAL_PRIVATE_MEMORY_H
#define COAL_PRIVATE_MEMORY_H

#include <stddef.h> /* size_t */

#include <coal/private/cdefs.h>

/**
 * coal_private_malloc
 *
 * See malloc().
 *
 * The purpose of this function is to throw an exception in
 * the event that malloc(3) fails, it might also be used to
 * provide an alternative malloc implementation.
 *
 * @param  (size_t) number of bytes to allocate
 * @return (void *) pointer to allocated memory
 */
coal_cfunspec void * coal_private_malloc (size_t size) coal_funattr_malloc;

/**
 * coal_private_realloc
 *
 * See realloc().
 * See coal_private_malloc().
 *
 * @param  (void *) pointer to memory block
 * @param  (size_t) size in bytes of new block
 * @return (void *) reallocated block
 */
coal_cfunspec void * coal_private_realloc (void * ptr, size_t size);

#endif /* COAL_PRIVATE_MEMORY_H */

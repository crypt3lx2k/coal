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

#ifndef COAL_CORE_MEMORY_H__
#define COAL_CORE_MEMORY_H__

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/memory.h> directly; use <coal/core/implementation.h> instead."
#endif

/**
 * coal_core_malloc
 * See malloc (3).
 * The purpose of this function
 * is to throw an exception in the event
 * that malloc (3) fails.
 *
 * @param  (size_t) number of bytes to allocate
 * @return (void *) pointer to allocated memory
 */
cfundecl__ (void * coal_core_malloc (size_t size)) __attribute__ ((malloc));

/**
 * coal_core_realloc
 * See realloc (3).
 * See coal_core_malloc.
 *
 * @param  (void *) pointer to memory block
 * @param  (size_t) size in bytes of new block
 * @return (void *) reallocated block
 */
cfundecl__ (void * coal_core_realloc (void * ptr, size_t size));

#endif /* COAL_CORE_MEMORY_H__ */

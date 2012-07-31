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

#include <stdlib.h>

#include <coal/error/OutOfMemoryError.h>
#include <coal/private/memory.h>

void * coal_private_malloc (size_t size) {
  void * block;

  block = malloc(size);

  if (block == NULL)
    coal_throw(coal_new(coal_error_OutOfMemoryError(),
			"%s: malloc of %zu bytes failed",
			__func__, size));

  return block;
}

void * coal_private_realloc (void * ptr, size_t size) {
  void * block;

  block = realloc(ptr, size);

  if (block == NULL)
    coal_throw(coal_new(coal_error_OutOfMemoryError(),
			"%s: realloc on %p of %zu bytes failed",
			__func__, ptr, size));

  return block;
}
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

#ifndef COAL_IO_FILE_H__
#define COAL_IO_FILE_H__

#include <coal/coal.h>

/**
 * coal_io_File
 * Class representing a file object.
 *
 * See fopen(3) for details on modes.
 *
 * @extends coal_lang_object
 * @constructor takes 2 arguments
 * @param (const char *) path of file
 * @param (const char *) mode to open file with
 */
cfundecl__ (const var coal_io_File (void))
  __attribute__ ((const));

#ifdef IO_NAMESPACE_POLLUTE
# define File coal_io_File
#endif

#endif /* COAL_IO_FILE_H__ */

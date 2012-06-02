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

#ifndef COAL_IO_IO_H
#define COAL_IO_IO_H

#include <stdio.h> /* FILE */
#include <coal/coal.h>

/**
 * coal_io_fprint
 *
 * Prints object to stream.
 *
 * @param  (val) object to be printed
 * @param  (FILE *) stream to print to
 * @return (int) non-negative number on success and EOF on error
 */
coal_cfunspec int coal_io_fprint (val object, FILE * stream);

/**
 * coal_io_fprintln
 *
 * Prints object to stream with a trailing newline.
 *
 * @param  (val) object to be printed
 * @param  (FILE *) stream to print to
 * @return (int) non-negative number on success and EOF on error
 */
coal_cfunspec int coal_io_fprintln (val object, FILE * stream);

/**
 * coal_io_print
 *
 * Prints object to stdout.
 *
 * @param  (val) object to be printed
 * @return (int) non-negative number on success and EOF on error
 */
coal_cfunspec int coal_io_print (val object);

/**
 * coal_io_println
 *
 * Prints object to stdout with a trailing newline.
 *
 * @param  (val) object to be printed
 * @return (int) non-negative number on success and EOF on error
 */
coal_cfunspec int coal_io_println (val object);

#ifdef COAL_IO_NAMESPACE_POLLUTE
# define fprint(o, s)   coal_io_fprint(o, s)
# define fprintln(o, s) coal_io_fprintln(o, s)
# define print(o)       coal_io_print(o)
# define println(o)     coal_io_println(o)
#endif

#endif /* COAL_IO_IO_H */

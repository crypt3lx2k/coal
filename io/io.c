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

#include <stdio.h>

#include <coal/core/implementation.h>
#include <coal/io/io.h>

int coal_io_fprint (const var object, FILE * stream) {
  var s = coal_lang_toString(object);
  int r;

  r = fputs(coal_lang_string_chars(s), stream);

  coal_del(s);

  return r;
}

int coal_io_fprintln (const var object, FILE * stream) {
  int r;

  r = coal_io_fprint(object, stream);
  putc('\n', stream);

  return r;
}

int coal_io_print (const var object) {
  return coal_io_fprint(object, stdout);
}

int coal_io_println (const var object) {
  return coal_io_fprintln(object, stdout);
}

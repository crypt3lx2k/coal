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
#include <string.h>

#include <coal/core/implementation.h>

#include <coal/util/iterator.h>
#include <coal/io/File/File_iterator.rep>

var File_iterator_constructor (var _self, va_list * app) {
  class(File_iterator) * self = _self;

  self->fp   = va_arg(*app, FILE *);
  self->done = false;

  memset(self->buffer, 0, BUFFER_SIZE);

  if (fgets(self->buffer, BUFFER_SIZE, self->fp) == NULL)
    self->done = true;

  return _self;
}

bool File_iterator_hasNext (const var _self) {
  const class(File_iterator) * self = _self;

  return !self->done;
}

var File_iterator_next (var _self) {
  class(File_iterator) * self = _self;
  var s;

  s = coal_new(coal_lang_string(), "%s", self->buffer);

  if (fgets(self->buffer, BUFFER_SIZE, self->fp) == NULL)
    self->done = true;

  return s;
}

SETUP_CLASS_DESCRIPTION(coal_io_File_iterator,
			coal_util_iterator(),
			LIBRARY_STR ".io.File.iterator",
			coal_lang_object(),
			sizeof(class(File_iterator)),
			/* object */
			INHERIT_METHOD,
			File_iterator_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			/* iterator */
			File_iterator_hasNext,
			File_iterator_next);

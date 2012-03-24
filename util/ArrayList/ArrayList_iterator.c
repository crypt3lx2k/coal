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

#include <coal/core/implementation.h>

#include <coal/util/iterator.h>
#include <coal/util/ArrayList/ArrayList_iterator.rep>

var ArrayList_iterator_constructor (var _self, va_list * app) {
  class(ArrayList_iterator) * self = _self;

  self->base = va_arg(*app, var *);
  self->head = va_arg(*app, var *);

  return _self;
}

bool ArrayList_iterator_hasNext (const var _self) {
  const class(ArrayList_iterator) * self = _self;

  return self->base < self->head;
}

var ArrayList_iterator_next (var _self) {
  class(ArrayList_iterator) * self = _self;

  return *self->base++;
}

SETUP_CLASS_DESCRIPTION(coal_util_ArrayList_iterator,
			coal_util_iterator(),
			LIBRARY_STR ".util.ArrayList.iterator",
			coal_lang_object(),
			sizeof(class(ArrayList_iterator)),
			INHERIT_METHOD,
			ArrayList_iterator_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			ArrayList_iterator_hasNext,
			ArrayList_iterator_next);

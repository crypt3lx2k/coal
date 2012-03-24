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

#include <coal/lang/iterable.h>
#include <coal/lang/iterable/iterable.rep>

var iterable_constructor (var _self, va_list * app) {
  const class(metaclass) * class = coal_lang_iterable();
  class(iterable) * self = _self;

  class->super->constructor(_self, app);

  OverrideMethod(self, iterator);

  return _self;
}

var coal_lang_iterable_iterator (const var _self) {
  const class(iterable) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_lang_iterable_iterator", class, coal_lang_iterable());

  return class->iterator(_self);
}

SETUP_CLASS_DESCRIPTION(coal_lang_iterable,
			coal_lang_metaclass(),
			LIBRARY_STR ".lang.iterable",
			coal_lang_metaclass(),
			sizeof(class(iterable)),
			INHERIT_METHOD,
			iterable_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);

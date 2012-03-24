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

#include <string.h>
#include <coal/core/implementation.h>

#include <coal/core/classes/subclass.h>
#include <coal/core/classes/subclass/subclass.rep>

var subclass_constructor (var _self, va_list * app) {
  class(metaclass) * self = _self;
  const class(metaclass) * super;
  const char * name;

  name  = va_arg(*app, const char *);
  super = va_arg(*app, const class(metaclass) *);

  memcpy(self,
	 super,
	 coal_lang_getSize(super));

  self->name  = name;
  self->super = super;

  return _self;
}

SETUP_CLASS_DESCRIPTION(coal_core_subclass,
			coal_lang_metaclass(),
			LIBRARY_STR ".core.subclass",
			coal_lang_metaclass(),
			sizeof(class(subclass)),
			INHERIT_METHOD,
			subclass_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);

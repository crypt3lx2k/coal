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

#include <string.h> /* memcpy */

#include <coal/private/library.h> /* LIBRARY_STR */
#include <coal/private/virtual_methods.h> /* INHERIT_METHOD */

#include <coal/base/Object.h> /* coal_base_Object_getSize */

#include <coal/private/classes/Subclass.h>
#include <coal/base/Metaclass/Metaclass.rep.h>

/* Subclass implements base.Object methods */

var Subclass_constructor (var _self, va_list * args) {
  class(Metaclass) * self = _self;
  const class(Metaclass) * super;
  const char * name;

  name  = va_arg(*args, const char *);
  super = va_arg(*args, const class(Metaclass) *);

  memcpy((char *) self,
	 (const char *) super,
	 coal_base_Object_getSize(super));

  self->name  = name;
  self->super = super;

  return _self;
}

SETUP_CLASS_DESCRIPTION(coal_private_Subclass,
			coal_base_Metaclass(),
			LIBRARY_STR ".private.Subclass",
			coal_base_Metaclass(),
			sizeof(class(Metaclass)),
			/* Object */
			INHERIT_METHOD,       /* cmp */
			Subclass_constructor,
			INHERIT_METHOD,       /* destructor */
			INHERIT_METHOD,       /* equals */
			INHERIT_METHOD,       /* hashCode */
			INHERIT_METHOD);      /* toString */

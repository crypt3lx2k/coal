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

#include <coal/lang/AbstractInstantiationError.h>

#include <coal/lang/abstract.h>
#include <coal/lang/abstract/abstract.rep>

var abstract_constructor (var self, va_list * app) {
  const class(metaclass) * class = coal_lang_getClass(self);

  /* deallocate */
  coal_del(self);
  va_end(*app);

  coal_throw(coal_new(coal_lang_AbstractInstantiationError(),
		      "abstract_constructor: an attempt was made to instantiate abstract class %s",
		      class->name));
}

SETUP_CLASS_DESCRIPTION(coal_lang_abstract,
			coal_lang_metaclass(),
			LIBRARY_STR ".lang.abstract",
			coal_lang_object(),
			sizeof(class(abstract)),
			INHERIT_METHOD,
			abstract_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);

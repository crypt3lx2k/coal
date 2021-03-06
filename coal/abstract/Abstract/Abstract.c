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

#include <coal/private/library.h>
#include <coal/private/virtual_methods.h>

#include <coal/base/Metaclass.h>
#include <coal/base/Metaclass/Metaclass.rep.h>
#include <coal/base/Object.h>

#include <coal/abstract/AbstractInstantiationError.h>

#include <coal/abstract/Abstract.h>
#include <coal/abstract/Abstract/Abstract.rep.h>

/* abstract.Abstract implements base.Object methods */

var Abstract_constructor (var self, va_list * args coal_attr_unused) {
  const class(Metaclass) * class;
  class = coal_base_Object_getClass(self);

  coal_throw(coal_new(coal_abstract_AbstractInstantiationError(),
		      "%s: an attempt was made to instantiate abstract class %s",
		      __func__, class->name));
}

SETUP_CLASS_DESCRIPTION(coal_abstract_Abstract,
			coal_base_Metaclass(),
			LIBRARY_PREFIX "abstract" LIBRARY_MODSEP "Abstract",
			coal_base_Object(),
			sizeof(class(Abstract)),
			/* Object */
			INHERIT_METHOD,       /* cmp */
			Abstract_constructor,
			INHERIT_METHOD,       /* destructor */
			INHERIT_METHOD,       /* equals */
			INHERIT_METHOD,       /* hashCode */
			INHERIT_METHOD);      /* toString */

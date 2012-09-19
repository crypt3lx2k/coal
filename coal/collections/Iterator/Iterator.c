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
#include <coal/private/object_orientation.h>
#include <coal/private/virtual_methods.h>

#include <coal/base/Metaclass.h>

#include <coal/collections/Iterator.h>
#include <coal/collections/Iterator/Iterator.rep.h>

/* collections.Iterator implements base.Object methods */

var Iterator_constructor (var _self, va_list * args) {
  const class(Metaclass) * class;
  class(Iterator) * self = _self;

  class = coal_collections_Iterator();
  class->super->constructor(_self, args);

  OverrideMethod(self, args, hasNext);
  OverrideMethod(self, args, next);

  return _self;
}

/* selector functions */

bool coal_collections_Iterator_hasNext (val self) {
  const class(Iterator) * class;
  class = coal_base_Object_getClass(self);

  CheckAndThrowMissingMethod(class,
			     coal_collections_Iterator());

  return class->hasNext(self);
}

val coal_collections_Iterator_next (var self) {
  const class(Iterator) * class;
  class = coal_base_Object_getClass(self);

  CheckAndThrowMissingMethod(class,
			     coal_collections_Iterator());

  return class->next(self);
}

SETUP_CLASS_DESCRIPTION(coal_collections_Iterator,
			coal_base_Metaclass(),
			LIBRARY_PREFIX "collections" LIBRARY_MODSEP "Iterator",
			coal_base_Metaclass(),
			sizeof(class(Iterator)),
			/* Object */
			INHERIT_METHOD,       /* cmp */
			Iterator_constructor,
			INHERIT_METHOD,       /* destructor */
			INHERIT_METHOD,       /* equals */
			INHERIT_METHOD,       /* hashCode */
			INHERIT_METHOD);      /* toString */

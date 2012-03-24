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
#include <coal/util/collection.h>

#include <coal/util/list.h>
#include <coal/util/list/list.rep>

var list_constructor (var _self, va_list * app) {
  const class(metaclass) * class = coal_util_list();
  class(list) * self = _self;

  class->super->constructor(_self, app);

  OverrideMethod(self, get);
  OverrideMethod(self, insert);
  OverrideMethod(self, set);

  return self;
}

var coal_util_list_get (const var _self, int index) {
  const class(list) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_list_get", class, coal_util_list());

  return class->get(_self, index);
}

bool coal_util_list_insert (var _self, int index, var elem) {
  const class(list) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_list_insert", class, coal_util_list());

  return class->insert(_self, index, elem);
}

var coal_util_list_set (var _self, int index, var elem) {
  const class(list) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_list_set", class, coal_util_list());

  return class->set(_self, index, elem);
}

SETUP_CLASS_DESCRIPTION(coal_util_list,
			coal_lang_metaclass(),
			LIBRARY_STR ".util.list",
			coal_util_collection(),
			sizeof(class(list)),
			INHERIT_METHOD,
			list_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);

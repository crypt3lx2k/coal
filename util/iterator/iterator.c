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
#include <coal/util/iterator/iterator.rep>

var iterator_constructor (var _self, va_list * app) {
  const class(metaclass) * class = coal_util_iterator();
  class(iterator) * self = _self;

  class->super->constructor(_self, app);

  OverrideMethod(self, hasNext);
  OverrideMethod(self, next);

  return _self;
}

bool coal_util_iterator_hasNext (const var _self) {
  const class(iterator) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_iterator_hasNext", class, coal_util_iterator());

  return class->hasNext(_self);
}

var coal_util_iterator_next (var _self) {
  const class(iterator) * class = coal_lang_getClass(_self);

  CheckAndThrowMissingMethodException("coal_util_iterator_next", class, coal_util_iterator());

  return class->next(_self);
}

SETUP_CLASS_DESCRIPTION(coal_util_iterator,
			coal_lang_metaclass(),
			LIBRARY_STR ".util.iterator",
			coal_lang_metaclass(),
			sizeof(class(iterator)),
			INHERIT_METHOD,
			iterator_constructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD);

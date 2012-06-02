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

#include <stddef.h> /* NULL, offsetof */
#include <stdint.h> /* intptr_t */
#include <string.h> /* memcpy */

#include <coal/private/library.h> /* LIBRARY_STR */
#include <coal/private/virtual_methods.h> /* OverrideMethod */

#include <coal/base/String.h>
#include <coal/base/Object.h>
#include <coal/base/Object/Object.rep>

#include <coal/base/Metaclass.h>
#include <coal/base/Metaclass/Metaclass.rep>

/* Object implements base.Object methods */

int Object_cmp (val self, val other) {
  return (intptr_t) self - (intptr_t) other;
}

var Object_constructor (var self, va_list * args coal_attr_unused) {
  return self;
}

var Object_destructor (var self) {
  return self;
}

bool Object_equals (val self, val other) {
  return self == other;
}

int Object_hashCode (val self) {
  return (intptr_t) self;
}

var Object_toString (val self) {
  int hash;
  const class(Metaclass) * class;

  class = coal_base_Object_getClass(self);
  hash  = coal_base_Object_hashCode(self);

  return coal_base_String_format("%s@%x",
				 class->name,
				 hash);
}

/* Metaclass implements base.Object methods */

var Metaclass_constructor (var _self, va_list * args) {
  class(Metaclass) * self = _self;
  size_t offset = offsetof(class(Metaclass), cmp);

  self->name  = va_arg(*args, char *);
  self->super = va_arg(*args, class(Metaclass) *);
  self->size  = va_arg(*args, size_t);

  /* copy every method pointer
     from the old class*/
  memcpy((char *) self + offset,
	 (char *) self->super + offset,
	 coal_base_Object_getSize(self->super) - offset);

  /* override the methods unless
     INHERIT_METHOD was passed */
  OverrideMethod(self, args, cmp);
  OverrideMethod(self, args, constructor);
  OverrideMethod(self, args, destructor);
  OverrideMethod(self, args, equals);
  OverrideMethod(self, args, hashCode);
  OverrideMethod(self, args, toString);

  return _self;
}

var Metaclass_destructor (var self coal_attr_unused) {
  /* Make sure we don't attempt to deallocate this */
  return NULL;
}

var Metaclass_toString (val _self) {
  const class(Metaclass) * self = _self;

  return coal_base_String_format("class %s",
				 self->name);
}

/* set up class descriptions for Object and Metaclass */

#define _metaclass (_classdescripts + 1)
#define _object    (_classdescripts)

static class(Metaclass) _classdescripts [] = {
  {
    {
      _metaclass,
      1
    },
    LIBRARY_STR ".base.Object",
    _object,
    sizeof(class(Object)),
    Object_cmp,
    Object_constructor,
    Object_destructor,
    Object_equals,
    Object_hashCode,
    Object_toString
  },
  {
    {
      _metaclass,
      1,
    },
    LIBRARY_STR ".base.Metaclass",
    _object,
    sizeof(class(Metaclass)),
    Object_cmp,
    Metaclass_constructor,
    Metaclass_destructor,
    Object_equals,
    Object_hashCode,
    Object_toString
  }
};

val coal_base_Metaclass (void) {
  return _metaclass;
}

val coal_base_Object (void) {
  return _object;
}

#undef _object
#undef _metaclass

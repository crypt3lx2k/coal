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

#include <coal/base/Object.h>
#include <coal/base/Object/Object.rep>

#include <coal/base/MetaClass.h>
#include <coal/base/MetaClass/MetaClass.rep>

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

var Object_toString (val self coal_attr_unused) {
  return NULL;
}

/* MetaClass implements base.Object methods */

var MetaClass_constructor (var _self, va_list * args) {
  class(MetaClass) * self = _self;
  size_t offset = offsetof(class(MetaClass), cmp);

  self->name  = va_arg(*args, char *);
  self->super = va_arg(*args, class(MetaClass) *);
  self->size  = va_arg(*args, size_t);

  memcpy((char *) self + offset,
	 (char *) self->super + offset,
	 coal_base_Object_getSize(self->super) - offset);

  OverrideMethod(self, args, cmp);
  OverrideMethod(self, args, constructor);
  OverrideMethod(self, args, destructor);
  OverrideMethod(self, args, equals);
  OverrideMethod(self, args, hashCode);
  OverrideMethod(self, args, toString);

  return _self;
}

var MetaClass_destructor (var self coal_attr_unused) {
  /* Make sure we don't attempt to deallocate this */
  return NULL;
}

var MetaClass_toString (val _self coal_attr_unused) {
  return NULL;
}

/* set up class descriptions for Object and MetaClass */

#define _metaclass (_classdescripts + 1)
#define _object    (_classdescripts)

static class(MetaClass) _classdescripts [] = {
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
    LIBRARY_STR ".base.MetaClass",
    _object,
    sizeof(class(MetaClass)),
    Object_cmp,
    MetaClass_constructor,
    MetaClass_destructor,
    Object_equals,
    Object_hashCode,
    Object_toString
  }
};

val coal_base_MetaClass (void) {
  return _metaclass;
}

val coal_base_Object (void) {
  return _object;
}

#undef _object
#undef _metaclass

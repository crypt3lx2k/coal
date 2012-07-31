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

#include <string.h> /* strcmp */

#include <coal/base/Object.h>
#include <coal/base/Metaclass/Metaclass.rep>

#include <coal/error/NullPointerException.h>

int coal_base_Object_cmp (val self, val other) {
  const class(Metaclass) * s_class;
  const class(Metaclass) * o_class;

  /* identically the same */
  if (self == other)
    return 0;

  s_class = coal_base_Object_getClass(self);
  o_class = coal_base_Object_getClass(other);

  /* self instance of other's class? */
  if (coal_instanceof(self, o_class))
    return o_class->cmp(self, other);
  /* other instance of self's class? */
  else if (coal_instanceof(other, s_class))
    return s_class->cmp(self, other);
  /* completely different types,
     we compare the class names
     as done in Python. */
  else
    return strcmp(s_class->name, o_class->name);
}

var coal_base_Object_constructor (var self, va_list * args) {
  const class(Metaclass) * class;

  class = coal_base_Object_getClass(self);

  return class->constructor(self, args);
}

var coal_base_Object_destructor (var self) {
  const class(Metaclass) * class;

  class = coal_base_Object_getClass(self);

  return class->destructor(self);
}

bool coal_base_Object_equals (val self, val other) {
  const class(Metaclass) * s_class;
  const class(Metaclass) * o_class;

  /* identically the same */
  if (self == other)
    return true;

  s_class = coal_base_Object_getClass(self);
  o_class = coal_base_Object_getClass(other);

  /* self instance of other's class? */
  if (coal_instanceof(self, o_class))
    return o_class->equals(self, other);
  /* other instance of self's class? */
  else if (coal_instanceof(other, s_class))
    return s_class->equals(self, other);
  /* completely different types,
     can't be equal */
  else
    return false;
}

val coal_base_Object_getClass (val _self) {
  const class(Object) * self = _self;

  if (self == NULL)
    coal_throw(coal_new(coal_error_NullPointerException(),
			"%s: null object",
			__func__));

  if (self->class == NULL)
    coal_throw(coal_new(coal_error_NullPointerException(),
			"%s: null class description",
			__func__));

  return self->class;
}

size_t coal_base_Object_getSize (val self) {
  const class(Metaclass) * class;

  class = coal_base_Object_getClass(self);

  return class->size;
}

size_t coal_base_Object_hashCode (val self) {
  const class(Metaclass) * class;

  class = coal_base_Object_getClass(self);

  return class->hashCode(self);
}

var coal_base_Object_toString (val self) {
  const class(Metaclass) * class;

  class = coal_base_Object_getClass(self);

  return class->toString(self);
}

/* looking for the class description setup?
   it's defined in base/Object/Object.c due
   to interdependency */

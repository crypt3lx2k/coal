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

#include <stdlib.h> /* free */

#include <coal/private/memory.h>
#include <coal/private/reference_counting.h>
#include <coal/private/try_catch.h>
#include <coal/private/virtual_methods.h>

#include <coal/io/io.h>

#include <coal/base/Object.h>
#include <coal/base/Object/Object.rep.h>

#include <coal/base/Metaclass.h>
#include <coal/base/Metaclass/Metaclass.rep.h>

#include <coal/error/IllegalStateException.h>
#include <coal/error/NullPointerException.h>
#include <coal/error/Throwable.h>

#include <coal/coal.h>

var coal_acquire (var object) {
  if (IS_GARBAGE(object))
    coal_throw(coal_new(coal_error_IllegalStateException(),
			"%s: tried to acquire an object with a zero reference count",
			__func__));

  return INCREMENT_REFERENCE_COUNT(object);
}

void coal_del (var object) {
  if (object == NULL)
    return;

  DECREMENT_REFERENCE_COUNT(object);

  if (IS_GARBAGE(object))
    free(coal_base_Object_destructor(object));
}

bool coal_instanceof (val object, val class) {
  const class(Metaclass) * current;

  if (class == NULL)
    coal_throw(coal_new(coal_error_NullPointerException(),
			"%s: null class description",
			__func__));

  current = coal_base_Object_getClass(object);

  if (current == class)
    return true;

  do {
    current = current->super;

    if (current == class)
      return true;
  } while (current != coal_base_Object());

  return false;
}

var coal_new (val _class, ...) {
  const class(Metaclass) * class = _class;
  class(Object) * object;
  va_list ap;

  if (class == NULL)
    coal_throw(coal_new(coal_error_NullPointerException(),
			"%s: null class description",
			__func__));

  CheckAndThrowMissingMethod(_class, coal_base_Metaclass());

  object = coal_private_malloc(class->size);

  object->class = class;
  object->reference_count = 1;

  coal_try {
    va_start(ap, _class);
    object = class->constructor(object, &ap);
  } coal_catch (coal_error_Throwable(), e coal_attr_unused) {
    free(object);
    coal_rethrow();
  } coal_finally {
    va_end(ap);
  } coal_try_end;

  return object;
}

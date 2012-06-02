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

#define _GNU_SOURCE
#include <stdio.h>  /* vasprintf */
#include <stdlib.h> /* free */
#include <string.h>

#include <coal/private/library.h>            /* LIBRARY_STR */
#include <coal/private/memory.h>             /* coal_private_malloc */
#include <coal/private/object_orientation.h> /* SETUP_CLASS_DESCRIPTION */

#include <coal/base/Object.h>
#include <coal/base/Metaclass.h>
#include <coal/base/String.h>
#include <coal/base/String/String.rep>

#include <coal/error/OutOfMemoryError.h>

/* String implements base.Object methods */

int String_cmp (val _self, val _other) {
  const class(String) * self  = _self;
  const class(String) * other = _other;

  return strcmp(self->str, other->str);
}

var String_constructor (var _self, va_list * args) {
  class(String) * self = _self;
  const char * src;

  src = va_arg(*args, const char *);

  /* there has to be a better way
     to do this kind of evil stuff */
  if (src == NULL) {
    self->str = NULL;
    self->len = 0;
    return _self;
  }

  self->len = va_arg(*args, size_t);

  if (self->len == 0)
    self->len = strlen(src);

  self->str =
    coal_private_malloc((self->len + 1) * sizeof(char));

  self->str =
    memcpy(self->str, src, (self->len+1) * sizeof(char));

  return _self;
}

var String_destructor (var _self) {
  class(String) * self = _self;

  free(self->str);
  self->str = NULL;
  self->len = 0;

  return _self;
}

bool String_equals (val _self, val _other) {
  const class(String) * self  = _self;
  const class(String) * other = _other;

  if (self->len != other->len)
    return false;
  else
    return memcmp(self->str, other->str,
		  self->len * sizeof(char)) == 0;
}

int String_hashCode (val _self) {
  const class(String) * self = _self;
  register size_t i;
  register int x, m;

  if (self->str[0] == '\0')
    return 0;

  x = self->str[0] << 7;
  m = 1000003;

  for (i = 0; i < self->len; i++)
    x = (x*m)^self->str[i];

  return x;
}

var String_toString (val self) {
  return coal_acquire((var) self);
}

/* static methods */

var coal_base_String_format (const char * fmt, ...) {
  char * buf;
  class(String) * s;
  va_list ap;

  /* create an empty string */
  s = coal_new(coal_base_String(), (char *) NULL, 0);

  va_start(ap, fmt);
  if (vasprintf(&buf, fmt, ap) == -1)
    coal_throw(coal_new(coal_error_OutOfMemoryError(),
			"%s: unable to allocate string",
			__func__));
  va_end(ap);

  s->str = buf;
  s->len = strlen(buf);

  return s;
}

SETUP_CLASS_DESCRIPTION(coal_base_String,
			coal_base_Metaclass(),
			LIBRARY_STR ".base.String",
			coal_base_Object(),
			sizeof(class(String)),
			/* Object */
			String_cmp,
			String_constructor,
			String_destructor,
			String_equals,
			String_hashCode,
			String_toString);

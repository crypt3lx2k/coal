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

#include <coal/private/library.h>            /* LIBRARY_STR */
#include <coal/private/object_orientation.h> /* SETUP_CLASS_DESCRIPTION */
#include <coal/private/virtual_methods.h>    /* INHERIT_METHOD */

#include <coal/base/Object.h>
#include <coal/base/Metaclass.h>
#include <coal/base/Throwable.h>
#include <coal/base/Throwable/Throwable.rep>

#include <coal/error/OutOfMemoryError.h>

/* Throwable implements base.Object methods */

var Throwable_constructor (var _self, va_list * args) {
  class(Throwable) * self = _self;
  const char * fmt;

  fmt = va_arg(*args, const char *);

  if (vasprintf(&self->message, fmt, *args) == -1)
    coal_throw(coal_new(coal_error_OutOfMemoryError(),
			"%s: string allocation failed",
			__func__));

  return _self;
}

var Throwable_destructor (var _self) {
  class(Throwable) * self = _self;

  free(self->message);
  self->message = NULL;

  return _self;
}

SETUP_CLASS_DESCRIPTION(coal_base_Throwable,
			coal_base_Metaclass(),
			LIBRARY_STR ".base.Throwable",
			coal_base_Object(),
			sizeof(class(Throwable)),
			/* Object */
			INHERIT_METHOD,        /* cmp */
			Throwable_constructor,
			Throwable_destructor,
			INHERIT_METHOD,        /* equals */
			INHERIT_METHOD,        /* hashCode */
			INHERIT_METHOD);       /* toString */

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

#ifndef COAL_PRIVATE_VIRTUAL_METHODS_H
#define COAL_PRIVATE_VIRTUAL_METHODS_H

#include <stdarg.h>
#include <coal/error/NoSuchMethodError.h>

typedef void (*vfunptr)();

/**
 * INHERIT_METHOD
 *
 * Tags a method for inheritance.
 */
#define INHERIT_METHOD ((vfunptr) 0)

/* overrides a method in a class description */
#define OverrideMethod(self, app, method)       \
  ({                                            \
    __typeof__(self->method) external =         \
      va_arg(*app, __typeof__(self->method));   \
                                                \
    if ((vfunptr) external == INHERIT_METHOD)   \
      ((void) 0);                               \
    else                                        \
      self->method = external;                  \
  })

#define CheckAndThrowMissingMethod(obj, klass)                  \
  if (! coal_instanceof(obj, klass))                            \
    coal_throw(coal_new(coal_error_NoSuchMethodError(),         \
                        "%s: invoked on an unsuitable object",  \
                        __func__))

#endif /* COAL_PRIVATE_VIRTUAL_METHODS_H */

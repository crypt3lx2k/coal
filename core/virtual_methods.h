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

#ifndef COAL_CORE_VIRTUAL_METHODS_H__
#define COAL_CORE_VIRTUAL_METHODS_H__

#include <stdint.h> /* intptr_t */
#include <coal/core/object_orientation.h>

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/virtual_methods.h> directly; use <coal/core/implementation.h> instead."
#endif

#include <coal/lang/NoSuchMethodError.h>

/**
 * coal_core_abstract_method
 * Throws an AbstractMethodException when called.
 */
cfundecl__ (void coal_core_abstract_method ())
  __attribute__ ((noreturn));

/* boilerplate for dynamically linked methods */
#define ClassCallTemplate(method, klass, self, ...)             \
  const class(klass) * class = coal_lang_getClass(self);        \
  return class->method(self, ##__VA_ARGS__)

/* overrides a method in a class description */
#define OverrideMethod(self, method)                            \
  ({                                                            \
    typeof(self->method) external =                             \
      va_arg(*app, typeof(self->method));                       \
                                                                \
    if ((intptr_t) external == INHERIT_METHOD)                  \
      self->method = self->method;                              \
    else if ((intptr_t) external == ABSTRACT_METHOD)            \
      self->method =                                            \
        (typeof(self->method)) coal_core_abstract_method;       \
    else                                                        \
      self->method = external;                                  \
  })

/* boilerplate for throwing an exception
   when a method is missing in an object */
#define CheckAndThrowMissingMethodException(method, self, klass)        \
  if (! coal_instanceof(self, klass))                                   \
    coal_throw(coal_new(coal_lang_NoSuchMethodError(),                  \
                        method ": invoked on an unsuitable object"))

#endif /* COAL_CORE_VIRTUAL_METHODS_H__ */

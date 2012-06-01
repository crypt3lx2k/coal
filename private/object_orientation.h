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

#ifndef COAL_PRIVATE_OBJECT_ORIENTATION_H
#define COAL_PRIVATE_OBJECT_ORIENTATION_H

#include <stdlib.h> /* free */
#include <coal/private/atomic.h>

/* designates the start of a class declaration. A class
   declaration is currently at the same form as a struct 
   declaration. */
#define class(name) \
  struct name

/* used to extend another class. this must be placed
   at the top of the class declaration to function. */
#define extends(name) \
  struct name name##__

/**
 * Sets up a class description.
 */
#define SETUP_CLASS_DESCRIPTION(name, ...)       \
  static val name##__ = NULL;                    \
                                                 \
  val name (void) {                              \
    var _desc = NULL;                            \
                                                 \
    if (name##__ == NULL) {                      \
      _desc = coal_new(__VA_ARGS__);             \
      if (!atomic_cas(&name##__, NULL, _desc)) { \
        /* someone else succeeded in swapping    \
           the value of the class description,   \
           we must attempt to deallocate */      \
        /* in case this is a metaclass with      \
           an actual destructor */               \
        coal_base_Object_destructor(_desc);      \
        /* in case it isn't (this is likely)     \
           we free the pointer returned from     \
           new directly, since we can't trust    \
           the return value of the destructor */ \
        free(_desc);                             \
      }                                          \
    }                                            \
                                                 \
    return name##__;                             \
  }

#endif /* COAL_PRIVATE_OBJECT_ORIENTATION_H */

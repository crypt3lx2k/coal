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

#include <pthread.h>

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
#define SETUP_CLASS_DESCRIPTION(name, ...)      \
  static val _c_##name;                         \
  static pthread_once_t _c_##name##once =       \
    PTHREAD_ONCE_INIT;                          \
                                                \
  static void _c_##name##init (void) {          \
    _c_##name = coal_new(__VA_ARGS__);          \
  }                                             \
                                                \
  val name (void) {                             \
    (void) pthread_once(&_c_##name##once,       \
                        _c_##name##init);       \
                                                \
    return _c_##name;                           \
  }

#endif /* COAL_PRIVATE_OBJECT_ORIENTATION_H */

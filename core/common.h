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

#ifndef COAL_CORE_COMMON_H__
#define COAL_CORE_COMMON_H__

/*
 * See bottom.
 */
/* #include <coal/core/utility_mutex.h> */

#include <coal/core/atomic.h>

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/common.h> directly; use <coal/core/implementation.h> instead."
#endif

/**
 * Sets up a class description.
 */
#define SETUP_CLASS_DESCRIPTION(name, ...)              \
  static const var name##__ = NULL;                     \
                                                        \
  const var name (void) {                               \
    var _desc = NULL;                                   \
                                                        \
    if (name##__ == NULL) {                             \
      _desc = coal_new(__VA_ARGS__);                    \
      if (!atomic_cas(&name##__, NULL, _desc)) {        \
        /* someone else succeeded in swapping           \
           the value of the class description,          \
           we must attempt to deallocate */             \
        /* in case this is a metaclass with             \
           an actual destructor */                      \
        coal_lang_destructor(_desc);                    \
        /* in case it isn't (this is likely)            \
           we free the pointer returned from            \
           new directly, since we can't trust           \
           the return value of the destructor */        \
        free(_desc);                                    \
      }                                                 \
    }                                                   \
                                                        \
    return name##__;                                    \
  }

/*
 * Old class description setup, used a mutex,
 * was inefficient when several threads wanted
 * to create many instances of the same class
 * concurrently.
 *
 * The reason this is still here is because it
 * is more efficient when it comes to sparse
 * concurrent initializations, so we might have
 * some of it in the future.
 */
/* #define SETUP_CLASS_DESCRIPTION(name, ...)      \ */
/*   static const var name##__ = NULL;             \ */
/*   static utility_mutex name##_##mutex##__ =     \ */
/*     utility_mutex_open();                       \ */
/*                                                 \ */
/*   const var name (void) {                       \ */
/*     utility_mutex_lock(&name##_##mutex##__);    \ */
/*     if (name##__ == NULL)                       \ */
/*       name##__ = coal_new(__VA_ARGS__);         \ */
/*     utility_mutex_unlock(&name##_##mutex##__);  \ */
/*                                                 \ */
/*     return name##__;                            \ */
/*   } */

#endif /* COAL_CORE_COMMON_H__ */

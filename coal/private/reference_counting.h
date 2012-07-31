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

#ifndef COAL_PRIVATE_REFERENCE_COUNTING_H
#define COAL_PRIVATE_REFERENCE_COUNTING_H

#include <coal/private/atomic.h>
#include <coal/base/Object/Object.rep.h>

/* Don't use these macros, use
   coal_acquire and coal_del instead */
/**
 * DECREMENT_REFERENCE_COUNT
 *
 * Decrements the reference counter of an object atomically.
 *
 * @param  (var) object in question
 * @return (var) object with decremented reference counter
 */
#define DECREMENT_REFERENCE_COUNT(obj)          \
  ({                                            \
    class(Object) * o__ = (obj);                \
    atomic_dec(&o__->reference_count);          \
  })

/**
 * GET_REFERENCE_COUNT
 *
 * Returns the current reference count of an object.
 *
 * @param  (var) object in question
 * @return (reference_counter_type) reference count of object
 */
#define GET_REFERENCE_COUNT(obj)                \
  ({                                            \
    const class(Object) * o__ = (obj);          \
    o__->reference_count;                       \
  })

/**
 * INCREMENT_REFERENCE_COUNT
 *
 * Increments the reference counter of an object atomically.
 *
 * @param  (var) object in question
 * @return (var) object with increased reference counter
 */
#define INCREMENT_REFERENCE_COUNT(obj)          \
  ({                                            \
    class(Object) * o__ = (obj);                \
    atomic_inc(&o__->reference_count);          \
    o__;                                        \
  })

/**
 * IS_GARBAGE
 *
 * Returns whether an object has no remaining references.
 *
 * @param  (val) object in question
 * @return (int) 1 if object's reference counter is 0 and 0 otherwise
 */
#define IS_GARBAGE(obj)                         \
  ({                                            \
    class(Object) * o__ = (obj);                \
    o__->reference_count == 0;                  \
  })

#endif /* COAL_PRIVATE_REFERENCE_COUNTING_H */

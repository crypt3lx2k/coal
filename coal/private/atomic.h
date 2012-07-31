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

#ifndef COAL_PRIVATE_ATOMIC_H
#define COAL_PRIVATE_ATOMIC_H

/* This is currently a pretty skimpy header, it's not at all
   compatible with the up and coming stdatomic.h and it has
   very little functionality. More will be added on a need to
   implement basis. */

/**
 * atomic(type)
 *
 * Atomic primitive integral type.
 *
 * Provides atomic lock-free CAS,
 * ADD, SUB, INC, DEC operations.
 *
 * Using this with a non integral type considered harmful.
 *
 * Mutating this variable in a threaded manner without using
 * the atomic functions will result in undefined behavior.
 *
 * In the documentation below, atomic(type) is compatible
 * with type.
 */
/* declared volatile so that the compiler doesn't swap
   things around or optimize it out of existence. */
#define atomic(type) \
  volatile type

/**
 * atomic_cas
 *
 * Performs an atomic compare and swap operation.
 *
 * @param  (atomic(type) *) pointer to value
 * @param  (atomic(type)) expected value
 * @param  (type) new value 
 * @return (bool) true if the swap was successful and false otherwise
 */
#define atomic_cas(ptr, old, new) \
  __sync_bool_compare_and_swap((ptr), (old), (new))

/**
 * atomic_add
 *
 * Atomically adds two numbers.
 *
 * @param  (atomic(type) *) pointer to value
 * @param  (type) value to add with
 * @return (atomic(type)) the new value
 */
#define atomic_add(ptr, val) \
  __sync_add_and_fetch((ptr), (val))

/**
 * atomic_sub
 *
 * Atomically subtracts two numbers.
 *
 * @param  (atomic(type) *) pointer to value
 * @param  (type) value to subtract with
 * @return (atomic(type)) the new value
 */
#define atomic_sub(ptr, val) \
  __sync_sub_and_fetch((ptr), (val))

/**
 * atomic_inc
 *
 * Atomically increments a number.
 *
 * @param  (atomic(type) *) pointer to number
 * @return (atomic(type)) new value of number
 */
#define atomic_inc(ptr) \
  atomic_add((ptr), 1)

/**
 * atomic_dec
 *
 * Atomically decrements a number.
 *
 * @param  (atomic(type) *) pointer to number
 * @return (atomic(type)) new value of number
 */
#define atomic_dec(ptr) \
  atomic_sub((ptr), 1)

#endif /* COAL_PRIVATE_ATOMIC_H */

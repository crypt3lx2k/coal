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

#ifndef COAL_PRIVATE_FUNCTION_POINTER_STACK_H
#define COAL_PRIVATE_FUNCTION_POINTER_STACK_H

/* keep this header clean for users, might be installed */

/*
 * We provide a minimal stack implementation, add stuff on a
 * need to implement basis.
 */

#include <stddef.h>
#include <coal/private/cdefs.h>

/**
 * Generic function pointer type.
 */
typedef void (*fn_pointer)();

/**
 * coal_private_fpstack
 *
 * Stack of function pointers, mirrors pointer stack as
 * much as possible.
 */
struct coal_private_fpstack {
  fn_pointer * base;
  fn_pointer * head;
  fn_pointer * end;
};

/**
 * COAL_PRIVATE_FPSTACK_INITIALIZER
 *
 * Valid constant initializer for an empty stack.
 */
#define COAL_PRIVATE_FPSTACK_INITIALIZER {NULL, NULL, NULL}

/**
 * coal_private_fpstack_destroy
 *
 * Frees underlying memory and resets pointers so that the
 * stack valid and empty.
 *
 * The stack pointers should be initialized either as a valid
 * stack or as to indicate an empty stack even before calling
 * this function.
 *
 * @param  (struct coal_private_fpstack *) stack to empty and reset
 */
coal_cfunspec void coal_private_fpstack_destroy (struct coal_private_fpstack * s);

/**
 * coal_private_fpstack_initialize
 *
 * Initializes the underlying memory to hold size number of
 * pointers.
 *
 * The stack pointers should be initialized either as a valid
 * stack or as to indicate an empty stack even before calling
 * this function.
 *
 * This function may also be used to resize or pre-allocate
 * the stack, if you cut the stack shorter than the number
 * of elements the excess elements will be irrevocably lost.
 *
 * @param  (struct coal_private_fpstack *) stack to initialize
 * @param  (size_t) number of pointers
 */
coal_cfunspec void coal_private_fpstack_initialize (struct coal_private_fpstack * s, size_t size);

/**
 * coal_private_fpstack_isEmpty
 *
 * Returns whether the stack is empty.
 *
 * @param  (const struct coal_private_fpstack *) stack to check
 * @return (int) nonzero if the stack is empty
 */
coal_cfunspec int coal_private_fpstack_isEmpty (const struct coal_private_fpstack * s);

/**
 * coal_private_fpstack_peek
 *
 * Returns the element at the top of the stack without
 * removing it.
 *
 * NULL is returned to indicate an empty stack.
 *
 * @param  (const struct coal_private_fpstack *) stack to inspect
 * @return (fn_pointer) topmost element
 */
coal_cfunspec fn_pointer coal_private_fpstack_peek (const struct coal_private_fpstack * s);

/**
 * coal_private_fpstack_pop
 *
 * Returns the element at the top of the stack also removing
 * it from the stack.
 *
 * NULL is returned to indicate an empty stack.
 *
 * @param  (struct coal_private_fpstack *) stack to pop element from
 * @return (fn_pointer) the former top of the stack
 */
coal_cfunspec fn_pointer coal_private_fpstack_pop (struct coal_private_fpstack * s);

/**
 * coal_private_fpstack_push
 *
 * Puts an element at the top of the stack.
 *
 * @param  (struct coal_private_fpstack *) stack to push element on
 * @param  (fn_pointer) element to put on the stack
 */
coal_cfunspec void coal_private_fpstack_push (struct coal_private_fpstack * s, fn_pointer e);

#endif /* COAL_PRIVATE_FUNCTION_POINTER_STACK_H */

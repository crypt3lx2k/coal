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

#ifndef COAL_PRIVATE_STACK_H
#define COAL_PRIVATE_STACK_H

/* keep this header clean for users, might be installed */

/*
 * We provide a minimal stack implementation, add stuff on a
 * need to implement basis.
 */

#include <stddef.h>
#include <coal/private/cdefs.h>

/**
 * coal_private_stack
 *
 * Stack of pointers. Provides O(1) destroy, initialize,
 * isEmpty, peek, pop and push operations.
 *
 * I don't provide any control over the growth rate, most of
 * these stacks are most likely to be very small so I keep it
 * moderate.
 *
 * The current error handling situation is very basic, when
 * an error is encountered it crashes the program as hard
 * as possible by calling abort().
 *
 * Rationale:
 *  There probably are better schemes but considering this
 *  stack is supposed to be used in critical components I
 *  think it's better to reliably work or reliably break.
 *
 *  It will be used to set up the exception handling code so
 *  the exception system can't reliably be used to handle
 *  errors here, it will therefore also be present in the try
 *  and catch macros so it's a good idea to keep the error
 *  handling as simple as possible as to avoid code bloat for
 *  the end user.
 *
 *  If we encounter a memory error in the exception stack we
 *  want to kill the application anyway, so we do not even
 *  return NULL and let the user handle the error.
 */
struct coal_private_stack {
  void ** base;
  void ** head;
  void ** end;
};

/**
 * COAL_PRIVATE_STACK_INITIALIZER
 *
 * Valid constant initializer for an empty stack.
 */
#define COAL_PRIVATE_STACK_INITIALIZER {NULL, NULL, NULL}

/**
 * coal_private_stack_destroy
 *
 * Frees underlying memory and resets pointers so that the
 * stack valid and empty.
 *
 * The stack pointers should be initialized either as a valid
 * stack or as to indicate an empty stack even before calling
 * this function.
 *
 * @param  (struct coal_private_stack *) stack to empty and reset
 */
coal_cfunspec void coal_private_stack_destroy (struct coal_private_stack * s);

/**
 * coal_private_stack_initialize
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
 * @param  (struct coal_private_stack *) stack to initialize
 * @param  (size_t) number of pointers
 */
coal_cfunspec void coal_private_stack_initialize (struct coal_private_stack * s, size_t size);

/**
 * coal_private_stack_isEmpty
 *
 * Returns whether the stack is empty.
 *
 * @param  (const struct coal_private_stack *) stack to check
 * @return (int) nonzero if the stack is empty
 */
coal_cfunspec int coal_private_stack_isEmpty (const struct coal_private_stack * s);

/**
 * coal_private_stack_peek
 *
 * Returns the element at the top of the stack without
 * removing it.
 *
 * NULL is returned to indicate an empty stack.
 *
 * It is not allowed to modify or mutate the element returned
 * through this function, if you need to mutate the element
 * it is better to pop the stack and then push the element
 * back on when you are done with the modifications.
 *
 * @param  (const struct coal_private_stack *) stack to inspect
 * @return (const void *) topmost element
 */
coal_cfunspec const void * coal_private_stack_peek (const struct coal_private_stack * s);

/**
 * coal_private_stack_pop
 *
 * Returns the element at the top of the stack also removing
 * it from the stack.
 *
 * NULL is returned to indicate an empty stack.
 *
 * @param  (struct coal_private_stack *) stack to pop element from
 * @return (void *) the former top of the stack
 */
coal_cfunspec void * coal_private_stack_pop (struct coal_private_stack * s);

/**
 * coal_private_stack_push
 *
 * Puts an element at the top of the stack.
 *
 * @param  (struct coal_private_stack *) stack to push element on
 * @param  (void *) element to put on the stack
 */
coal_cfunspec void coal_private_stack_push (struct coal_private_stack * s, void * e);

#endif /* COAL_PRIVATE_STACK_H */

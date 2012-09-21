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

#ifndef COAL_PRIVATE_TEMPLATES_STACK_H
#define COAL_PRIVATE_TEMPLATES_STACK_H

/* ONLY USE THIS STACK HIDDEN BEHIND SOME LAYER WHEN YOU'RE
   TARGETING THE END-USER, NEVER LET IT LEAK OUT. */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * STACK_INITIALIZER
 *
 * Valid constant initializer for an empty stack.
 */
#define STACK_INITIALIZER {NULL, NULL, NULL}

/**
 * STACK_RESIZE_FACTOR
 *
 * Factor to resize stack with when more space is needed.
 */
#define STACK_RESIZE_FACTOR (0.70)

/**
 * stack(type)
 *
 * Generic stack. Provides O(1) destroy, initialize, isEmpty,
 * peek, pop and push operations.
 *
 * If an allocation error happens we print an error message to
 * stderr and then crash as hard as possible by calling
 * abort().
 *
 * Since this stack is used in the exception handling system
 * we can't use that to indicate errors. Better schemes
 * made by smarter people probably exist.
 */
#define stack(type)                             \
  struct {                                      \
    type * base;                                \
    type * head;                                \
    type * end;                                 \
  }

/* return how many members currently in stack */
#define _stack_members(stack_ptr)               \
  ((stack_ptr)->head - (stack_ptr)->base)

/* return new size based on old size and resize factor */
#define _stack_newSize(old_size)                \
  ((old_size) * (1.0 + STACK_RESIZE_FACTOR) + 1)

/* return how many vacant slots there are in the stack */
#define _stack_vacancies(stack_ptr)             \
  ((stack_ptr)->end - (stack_ptr)->head)

/**
 * stack_destroy
 *
 * Frees underlying memory and resets pointers so that the
 * stack valid and empty.
 *
 * The stack pointers should be initialized either as a valid
 * stack or as to indicate an empty stack even before calling
 * this function.
 *
 * @param  (stack(type) *) stack to empty and reset
 */
#define stack_destroy(stack_ptr)                \
  do {                                          \
    __typeof__(stack_ptr) _s = (stack_ptr);     \
                                                \
    free(_s->base);                             \
                                                \
    _s->base = NULL;                            \
    _s->head = NULL;                            \
    _s->end  = NULL;                            \
  } while (0)

/**
 * stack_initialize
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
 * @param  (stack(type) *) stack to initialize
 * @param  (size_t) number of pointers
 */
#define stack_initialize(stack_ptr, size)               \
  do {                                                  \
    __typeof__(stack_ptr) _sp = (stack_ptr);            \
    size_t _si = (size);                                \
    size_t _me = _stack_members(_sp);                   \
                                                        \
    _sp->base =                                         \
      realloc(_sp->base, _si * sizeof(*_sp->base));     \
                                                        \
    if (_sp->base == NULL) {                            \
      perror("fatal stack error");                      \
      abort();                                          \
    }                                                   \
                                                        \
    _sp->head = _sp->base + (_me < _si ? _me : _si);    \
    _sp->end  = _sp->base + _si;                        \
  } while (0)

/**
 * stack_isEmpty
 *
 * Returns whether the stack is empty.
 *
 * @param  (stack(type) *) stack to check
 * @return (int) nonzero if the stack is empty
 */
#define stack_isEmpty(stack_ptr)                \
  ({                                            \
    __typeof__(stack_ptr) _sp = (stack_ptr);    \
                                                \
    _sp->base == _sp->head;                     \
  })

/**
 * coal_private_pstack_peek
 *
 * Returns the element at the top of the stack without
 * removing it.
 *
 * If the stack is already empty then undefined behavior
 * occurs, it is not allowed to call this function without
 * knowing first that stack has members (by calling
 * stack_isEmpty()).
 *
 * It is not allowed to modify or mutate the element returned
 * through this function, if you need to mutate the element
 * it is better to pop the stack and then push the element
 * back on when you are done with the modifications.
 *
 * @param  (stack(type) *) stack to inspect
 * @return (type) topmost element
 */
#define stack_peek(stack_ptr)                   \
  (*((stack_ptr)->head)-1)

/**
 * coal_private_pstack_pop
 *
 * Returns the element at the top of the stack also removing
 * it from the stack.
 *
 * If the stack is already empty then undefined behavior
 * occurs, it is not allowed to call this function without
 * knowing first that stack has members (by calling
 * stack_isEmpty()).
 *
 * @param  (stack(type) *) stack to pop element from
 * @return (type) the former top of the stack
 */
#define stack_pop(stack_ptr)                    \
  (*(--(stack_ptr)->head))

/**
 * coal_private_pstack_push
 *
 * Puts an element at the top of the stack.
 *
 * @param  (stack(type) *) stack to push element on
 * @param  (type) element to put on the stack
 */
#define stack_push(stack_ptr, element)          \
  do {                                          \
    __typeof__(stack_ptr) _s = (stack_ptr);     \
    __typeof__(*_s->base) _e = (element);       \
    size_t _v = _stack_vacancies(_s);           \
                                                \
    if (_v == 0) {                              \
      size_t _m = _stack_members(_s);           \
      size_t _n = _stack_newSize(_m);           \
                                                \
      stack_initialize(_s, _n);                 \
    }                                           \
                                                \
    *_s->head++ = _e;                           \
  } while (0)

#endif /* COAL_PRIVATE_TEMPLATES_STACK_H */

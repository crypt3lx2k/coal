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

#include <stdio.h> /* perror */
#include <stdlib.h>

#include "stack.h"

#define COAL_PRIVATE_STACK_RESIZE_FACTOR 0.7

static size_t
coal_private_stack_members (const struct coal_private_stack * s) {
  return (s->head - s->base);
}

static size_t
coal_private_stack_newSize (size_t old_size) {
  return (old_size * (1.0 + COAL_PRIVATE_STACK_RESIZE_FACTOR)) + 1;
}

static size_t
coal_private_stack_vacancies (const struct coal_private_stack * s) {
  return (s->end - s->head);
}

void coal_private_stack_destroy (struct coal_private_stack * s) {
  free(s->base);

  s->base = NULL;
  s->head = NULL;
  s->end  = NULL;
}

void coal_private_stack_initialize (struct coal_private_stack * s, size_t size) {
  size_t members = coal_private_stack_members(s);

  s->base = realloc(s->base, size * sizeof(void *));

  if (s->base == NULL) {
    perror("fatal stack error");
    abort();
  }

  s->head = s->base + (members < size ? members : size);
  s->end  = s->base + size;
}

int coal_private_stack_isEmpty (const struct coal_private_stack * s) {
  return s->base == s->head;
}

const void * coal_private_stack_peek (const struct coal_private_stack * s) {
  return (s->base == s->head) ? NULL : *(s->head-1);
}

void * coal_private_stack_pop (struct coal_private_stack * s) {
  return (s->base == s->head) ? NULL : *(--s->head);
}

void coal_private_stack_push (struct coal_private_stack * s, void * e) {
  size_t vacancies = coal_private_stack_vacancies(s);

  if (vacancies == 0) {
    size_t members = coal_private_stack_members(s);
    size_t new_size = coal_private_stack_newSize(members);

    coal_private_stack_initialize(s, new_size);
  }

  *s->head++ = e;
}

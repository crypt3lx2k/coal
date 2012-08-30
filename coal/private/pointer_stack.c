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

#include <coal/private/pointer_stack.h>

#define COAL_PRIVATE_PSTACK_RESIZE_FACTOR 0.7

static size_t
coal_private_pstack_members (const struct coal_private_pstack * s) {
  return (s->head - s->base);
}

static size_t
coal_private_pstack_newSize (size_t old_size) {
  return (old_size * (1.0 + COAL_PRIVATE_PSTACK_RESIZE_FACTOR)) + 1;
}

static size_t
coal_private_pstack_vacancies (const struct coal_private_pstack * s) {
  return (s->end - s->head);
}

void coal_private_pstack_destroy (struct coal_private_pstack * s) {
  free(s->base);

  s->base = NULL;
  s->head = NULL;
  s->end  = NULL;
}

void coal_private_pstack_initialize (struct coal_private_pstack * s, size_t size) {
  size_t members = coal_private_pstack_members(s);

  s->base = realloc(s->base, size * sizeof(void *));

  if (s->base == NULL) {
    perror("fatal stack error");
    abort();
  }

  s->head = s->base + (members < size ? members : size);
  s->end  = s->base + size;
}

int coal_private_pstack_isEmpty (const struct coal_private_pstack * s) {
  return s->base == s->head;
}

const void * coal_private_pstack_peek (const struct coal_private_pstack * s) {
  return (s->base == s->head) ? NULL : *(s->head-1);
}

void * coal_private_pstack_pop (struct coal_private_pstack * s) {
  return (s->base == s->head) ? NULL : *(--s->head);
}

void coal_private_pstack_push (struct coal_private_pstack * s, void * e) {
  size_t vacancies = coal_private_pstack_vacancies(s);

  if (vacancies == 0) {
    size_t members = coal_private_pstack_members(s);
    size_t new_size = coal_private_pstack_newSize(members);

    coal_private_pstack_initialize(s, new_size);
  }

  *s->head++ = e;
}

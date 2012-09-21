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

#include <coal/private/thread_local.h>
#include <coal/private/templates/stack.h>

#include <coal/private/cleanup_stack.h>

struct cleanup {
  coal_private_cleanup_fn routine;
  void * args;
};

static thread_local stack(struct cleanup) cleanup_stack =
  STACK_INITIALIZER;

void coal_private_cleanup_pop (int execute) {
  struct cleanup h;

  if (stack_isEmpty(&cleanup_stack))
    return;

  h = stack_pop(&cleanup_stack);

  if (execute)
    h.routine(h.args);
}

void coal_private_cleanup_push (coal_private_cleanup_fn routine, void * args) {
  struct cleanup h;

  h.routine = routine;
  h.args    = args;

  stack_push(&cleanup_stack, h);
}

void coal_private_cleanup_run_all (void * ign coal_attr_unused) {
  while (!stack_isEmpty(&cleanup_stack))
    coal_private_cleanup_pop(1);

  stack_destroy(&cleanup_stack);
}

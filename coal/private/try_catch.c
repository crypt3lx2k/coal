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

#include <coal/private/cleanup_stack.h>
#include <coal/private/thread_local.h>
#include <coal/private/templates/stack.h>

#include <coal/private/try_catch.h>

typedef stack(void *) pstack;

static thread_local pstack exception_s = STACK_INITIALIZER;

static thread_local int exception_s_cleanup_once = 0;

static void exception_s_cleanup_routine (void * args) {
  stack_destroy( (pstack *) args );
}

bool coal_private_try_isEmpty (void) {
  return stack_isEmpty(&exception_s);
}

struct _coal_private_try_context *
coal_private_try_pop (void) {
  return stack_pop(&exception_s);
}

void
coal_private_try_push (struct _coal_private_try_context * c) {
  if (! exception_s_cleanup_once) {
    coal_private_cleanup_push(exception_s_cleanup_routine,
			      &exception_s);
    exception_s_cleanup_once = 1;
  }

  stack_push(&exception_s, c);
}

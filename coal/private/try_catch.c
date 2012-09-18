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
#include <coal/private/pointer_stack.h>
#include <coal/private/thread_local.h>

#include <coal/private/try_catch.h>

static thread_local struct coal_private_pstack exception_s =
  COAL_PRIVATE_PSTACK_INITIALIZER;

static thread_local int exception_s_cleanup_once = 0;

static void exception_s_cleanup_routine (void * args) {
  coal_private_pstack_destroy(args);
}

bool coal_private_try_isEmpty (void) {
  return coal_private_pstack_isEmpty(&exception_s);
}

struct _coal_private_try_context *
coal_private_try_pop (void) {
  return coal_private_pstack_pop(&exception_s);
}

void
coal_private_try_push (struct _coal_private_try_context * c) {
  if (! exception_s_cleanup_once) {
    coal_private_cleanup_push(exception_s_cleanup_routine,
			      &exception_s);
    exception_s_cleanup_once = 1;
  }

  return coal_private_pstack_push(&exception_s, c);
}

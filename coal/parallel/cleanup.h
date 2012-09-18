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

#ifndef COAL_PARALLEL_CLEANUP_H
#define COAL_PARALLEL_CLEANUP_H

#include <coal/private/cleanup_stack.h>

/**
 * coal_parallel_cleanup_fn
 *
 * Type for cleanup routines.
 *
 * This type is defined such that
 * typedef void (*coal_parallel_cleanup_fn)(void *);
 * would be a valid typedef.
 */
typedef coal_private_cleanup_fn coal_parallel_cleanup_fn;

/**
 * coal_parallel_cleanup_pop
 *
 * Pops the top of the thread local cleanup stack, optionally
 * executing the cleanup routine.
 *
 * @param  (int) whether to execute the cleanup routine
 */
#define coal_parallel_cleanup_pop(execute) \
  coal_private_cleanup_pop(execute)

/**
 * coal_parallel_cleanup_push
 *
 * Pushes a cleanup routine to the top of the thread local
 * cleanup stack, together with arguments.
 *
 * @param  (coal_parallel_cleanup_fn) cleanup routine
 * @param  (void *) arguments to the cleanup routine
 */
#define coal_parallel_cleanup_push(routine, args) \
  coal_private_cleanup_push(routine, args)

#ifdef COAL_PARALLEL_NAMESPACE_POLLUTE
/* should this be a typedef? */
# define cleanup_fn         coal_parallel_cleanup_fn
# define cleanup_pop(e)     coal_parallel_cleanup_pop(e)
# define cleanup_push(r, a) coal_parallel_cleanup_push(r, a)
#endif /* COAL_PARALLEL_NAMESPACE_POLLUTE */

#endif /* COAL_PARALLEL_CLEANUP_H */

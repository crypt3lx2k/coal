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

#ifndef COAL_PRIVATE_CLEANUP_STACK_H
#define COAL_PRIVATE_CLEANUP_STACK_H

/* keep this header clean for users, might be installed */

#include <coal/private/cdefs.h>

/**
 * Type for cleanup routines.
 */
typedef void (*coal_private_cleanup_fn)(void *);

/**
 * coal_private_cleanup_pop
 *
 * Pops the top of the cleanup stack, optionally executing it.
 *
 * @param  (int) whether to execute the cleanup handler
 */
coal_cfunspec void coal_private_cleanup_pop (int execute);

/**
 * coal_private_cleanup_push
 *
 * Pushes a cleanup routine to the top of the cleanup stack,
 * together with arguments.
 *
 * @param  (coal_private_cleanup_fn) cleanup routine
 * @param  (void *) arguments to cleanup routine
 */
coal_cfunspec void coal_private_cleanup_push (coal_private_cleanup_fn routine, void * args);

/**
 * coal_private_cleanup_run_all
 *
 * Runs every cleanup function while cleaning the stack.
 *
 * @param  (void *) unused parameter
 */
coal_cfunspec void coal_private_cleanup_run_all (void * ign);

#endif /* COAL_PRIVATE_CLEANUP_STACK_H */

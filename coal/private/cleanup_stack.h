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

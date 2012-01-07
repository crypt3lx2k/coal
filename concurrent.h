#ifndef COAL_CONCURRENT_H__
#define COAL_CONCURRENT_H__

/*
 * This file is here as I feel that there is
 * no point in leaking these functions into
 * the users namespace unless the user
 * explicitly asks for them as they are not
 * particularly useful to the average user.
 */

#include <coal/coal.h>

/**
 * coal_concurrent_exit
 * Causes the calling thread to
 * stop executing.
 *
 * This function takes no parameters
 * and does not return.
 *
 * This function always succeeds.
 */
cfundecl__ (void coal_concurrent_exit (void)) __attribute__ ((noreturn));

#endif /* COAL_CONCURRENT_H__ */

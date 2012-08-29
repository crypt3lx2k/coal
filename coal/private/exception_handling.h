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

#ifndef COAL_PRIVATE_EXCEPTION_HANDLING_H
#define COAL_PRIVATE_EXCEPTION_HANDLING_H

#include <coal/private/cdefs.h>

/* Coal exception analogue ANSI-C signal handling interface */

/* I don't see the need for things like POSIX sigaction yet as
   coal exceptions don't come with most of the problems that
   signals present and that exceptions in themselves are like
   (or can be used as) siginfo_t structures. */

/**
 * coal_exhandler_fn
 *
 * Type for exception handling functions.
 *
 * The input parameter functions of this type will receive is
 * the thrown exception. You must not attempt to delete this
 * exception from within this function.
 *
 * Doing things that might cause exceptions to be thrown
 * without handling them from within this function will
 * typically cause an infinite loop.
 *
 * If this function returns then the application will print
 * whatever information is available and exit, so currently
 * there is no way outside of try-catch macros to successfully
 * handle an exception, this might be subject to change.
 *
 * How the system currently works is that when an exception is
 * thrown, it first checks the exception handling stack for
 * any try-blocks and jumps to them if they are present. If
 * no such blocks are present then it calls the exception
 * handling function, the default exception handling function
 * does nothing.
 */
typedef void (*coal_exhandler_fn)(val);

/**
 * COAL_EX_DFL
 *
 * When used as an argument to the coal_exhandler_set()
 * function this value indicates that the default behavior
 * should be used.
 */
#define COAL_EX_DFL ((coal_exhandler_fn) 0)

/* other sig codes present in ANSI-C are SIG_ERR and SIG_IGN,
   which indicate error in calls to signal and tells the
   implementation to ignore a signal of a given type
   respectively, an error code might be useful but since there
   are basically no benign exceptions I don't see how an
   ignore code could be useful. */

/**
 * coal_exhandler_set
 *
 * Sets the given function to be used as the new exception
 * handling function. See coal_exhandler_fn for details on
 * exception handling functions.
 *
 * The old exception handling function is returned.
 *
 * @param  (coal_exhandler_fn) new exception handler
 * @return (coal_exhandler_fn) old exception handler
 */
coal_cfunspec coal_exhandler_fn coal_exhandler_set (coal_exhandler_fn func);

#endif /* COAL_PRIVATE_EXCEPTION_HANDLING_H */

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

#ifndef COAL_PARALLEL_THREAD_H
#define COAL_PARALLEL_THREAD_H

#include <coal/base/Object.h>

/**
 * coal_parallel_Thread
 *
 * Class that represents a thread of execution.
 *
 * @extends coal_base_Object
 * @constructor takes 2 arguments
 * @param (void *(*start_routine) (void *)) thread target
 * @param (void *) arguments to target
 */
coal_cfunspec val coal_parallel_Thread (void) coal_funattr_const;

/**
 * coal_parallel_Thread_exit
 *
 * This static method terminates the calling thread.
 *
 * The return value passed to this method will be available
 * for other threads that join with this thread.
 *
 * Returning from the target function is equivalent to calling
 * this function with the value returned.
 *
 * This function does not return.
 *
 * @static
 * @param (void *) return value
 */
noreturn coal_cfunspec void coal_parallel_Thread_exit (void * retval);

/**
 * coal_parallel_Thread_join
 *
 * Waits for another thread to finish.
 *
 * @param  (val) thread to join with
 * @return (void *) return value of joined thread
 */
coal_cfunspec void * coal_parallel_Thread_join (val thread);

/**
 * coal_parallel_Thread_start
 *
 * Starts executing a thread.
 *
 * @param (var) thread to start
 */
coal_cfunspec void coal_parallel_Thread_start (var self);

#ifdef COAL_PARALLEL_NAMESPACE_POLLUTE
# define Thread()        coal_parallel_Thread()
# define Thread_exit(r)  coal_parallel_Thread_exit(r)
# define Thread_join(t)  coal_parallel_Thread_join(t)
# define Thread_start(s) coal_parallel_Thread_start(s)
#endif

#ifdef COAL_PARALLEL_THREAD_NAMESPACE_POLLUTE
# define exit(r)  coal_parallel_Thread_exit(r)
# define join(t)  coal_parallel_Thread_join(t)
# define start(s) coal_parallel_Thread_start(s)
#endif

#endif /* COAL_PARALLEL_THREAD_H */

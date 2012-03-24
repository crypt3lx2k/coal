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

#ifndef COAL_LANG_THREAD_H__
#define COAL_LANG_THREAD_H__

#include <coal/coal.h>

/**
 * coal_lang_thread
 * Class that represent a thread
 * of execution.
 *
 * @extends coal_lang_object
 * @constructor takes 2 arguments
 * @param (void *(*start_routine) (void *)) thread target
 * @param (void *) arguments to target
 */
cfundecl__ (const var coal_lang_thread (void))
  __attribute__ ((const));

/**
 * coal_lang_thread_exit
 * Causes the calling thread to
 * stop executing.
 *
 * This function takes no parameters
 * and does not return.
 *
 * This function always succeeds.
 */
cfundecl__ (void coal_lang_thread_exit (void)) __attribute__ ((noreturn));

/**
 * coal_lang_thread_join
 * Waits for thread to finish.
 *
 * @param (var) the thread in question
 */
cfundecl__ (void coal_lang_thread_join (var self));

/**
 * coal_lang_thread_start
 * Starts executing thread.
 *
 * @param (var) the thread in question
 */
cfundecl__ (void coal_lang_thread_start (var self));

#ifdef LANG_NAMESPACE_POLLUTE
# define thread       coal_lang_thread
# define thread_exit  coal_lang_thread_exit
# define thread_join  coal_lang_thread_join
# define thread_start coal_lang_thread_start
#endif

#ifdef THREAD_NAMESPACE_POLLUTE
# define exit  coal_lang_thread_exit
# define join  coal_lang_thread_join
# define start coal_lang_thread_start
#endif

#endif /* COAL_LANG_THREAD_H__ */

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

#ifndef COAL_PARALLEL_THREAD_REP_H
#define COAL_PARALLEL_THREAD_REP_H

#include <stdbool.h>

#include <pthread.h>

#include <coal/private/atomic.h>
#include <coal/base/Object/Object.rep.h>

class (Thread) {
  extends(Object);

  /* see pthread_create, will add more attributes as we go
     along */
  pthread_t thread;
  /* pthread_attr_t attr; */

  void *(*start_routine) (void *);
  void * args;

  /* flag to indicate whether thread has been started yet */
  atomic(bool) active;
};

#endif /* COAL_PARALLEL_THREAD_REP_H */

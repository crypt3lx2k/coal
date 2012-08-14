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

#ifndef COAL_PRIVATE_THREAD_LOCAL_H
#define COAL_PRIVATE_THREAD_LOCAL_H

/* keep this header clean for users, might be installed */

#if __STDC_VERSION__ >= 201000L
# include <threads.h>
#elif __GNUC__
# define thread_local __thread
#else
# warning "included file coal/private/thread_local.h without compiler support for thread local storage, coal will not work properly in a threaded manner"
# define thread_local
#endif /* __STDC_VERSION__ >= 201000L # C11 or newer */

#endif /* COAL_PRIVATE_THREAD_LOCAL_H */

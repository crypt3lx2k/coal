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

#ifndef COAL_PRIVATE_BRANCHING
#define COAL_PRIVATE_BRANCHING

/* keep this header clean for users, might be installed */

/*
 * Provide some simple defintions for mitigating potentially
 * expensive overhead, currently used in error checking.
 */
#ifdef __GNUC__

# define coal_unlikely(exp) \
  (__builtin_expect(!!(exp), 0))

# define coal_likely(exp) \
  (__builtin_expect(!!(exp), 1))

#else /* not __GNUC__ */

# define coal_unlikely(exp) (!!(exp))
# define coal_likely(exp)   (!!(exp))

#endif /* __GNUC__ */

#endif /* COAL_PRIVATE_BRANCHING */

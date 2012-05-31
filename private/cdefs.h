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

#ifndef COAL_PRIVATE_CDEFS_H
#define COAL_PRIVATE_CDEFS_H

/*
 * We have moved from defines to two separate typedefs.
 *
 * Originally we only had a single var type which was defined
 * to be void * so that const would behave nicely. If const
 * is used on a typedef'd pointer type then the variable
 * itself is constant and not the object it points to.
 *
 * A bad side effect of using a define to something like a
 * void * is that you may only declare a single variable per
 * line or else the declaration would become something like
 * this,
 *
 * var o, e;
 *    -->
 * void * o, e;
 *
 * with messy consequences.
 *
 * To address this we now have two typedef'd types, val and
 * var each representing an immutable and a mutable object
 * respectively.
 *
 * Whether this is a good move or not only time will tell.
 */

/**
 * Object constant type.
 */
typedef const void * val;

/**
 * Object variable type.
 */
typedef void * var;

/* check for C11 noreturn */
/* the actual value of this constant should probably be
   201112L but apparently the committee didn't replace
   201ymmL in the finished version of the standard.
   this is of course subject to change, see
   www.open-std.org/jtc1/sc22/wg14/www/docs/dr_411.htm
   for details. */
#if __STDC_VERSION__ >= 201000L
# define noreturn _Noreturn
#elif __GNUC__
# define noreturn \
  __attribute__ ((__noreturn__))
#else
# define noreturn
#endif /* __STDC_VERSION__ >= 201000L # C11 or newer */

#ifdef __GNUC__
/* this is here in case we need to change how
   every function is declared in the future. */
/* the extern inline is a GNU-C construct which is not
   allowed in ISO-C unless the function is also defined in
   in the same translation unit */
# define coal_cfunspec \
  extern inline

# define coal_funattr_const \
  __attribute__ ((__const__))

# define coal_funattr_malloc \
  __attribute__ ((__malloc__))

# define coal_attr_unused \
  __attribute__ ((__unused__))
#else
/* provide empty definitions for compilers that don't support
   GNU-C, the likelihood of this library actually compiling
   without GNU-C support I'm fairly certain is 0, but in case
   of any future decisions this would be one less thing to
   worry about. */
# define coal_cfunspec extern

# define coal_funattr_const

# define coal_funattr_malloc

# define coal_attr_unused

#endif /* __GNUC__ */

#endif /* COAL_PRIVATE_CDEFS_H */

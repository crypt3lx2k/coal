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

#ifndef COAL_TESTING_ASSERT_H
#define COAL_TESTING_ASSERT_H

#include <stddef.h> /* NULL */

#include <coal/private/branching.h>
#include <coal/private/preprocessor.h>

#include <coal/base/Object.h>
#include <coal/testing/AssertionError.h>

/**
 * coal_testing_assert
 *
 * Asserts that a condition is true and throws an
 * AssertionError if it is not.
 *
 * @param  (cond) boolean condition
 */
#define coal_testing_assert(cond)			    \
  do {							    \
    if (coal_unlikely(!(cond)))				    \
      coal_throw(coal_new(coal_testing_AssertionError(),    \
			  "assertion %s failed",	    \
			  COAL_STRINGIFY_EXPANSION(cond))); \
  } while (0)

/**
 * coal_testing_assert_equals
 *
 * Asserts that two objects are equal.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_testing_assert_equals(a, b) \
  coal_testing_assert(coal_base_Object_equals((a), (b)))

/**
 * coal_testing_assert_greater
 *
 * Asserts that one object is greater than another object.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_testing_assert_greater(a, b) \
  coal_testing_assert(coal_base_Object_cmp((a), (b)) > 0)

/**
 * coal_testing_assert_greater_or_equals
 *
 * Asserts that one object is greater than or equal to
 * another object.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_testing_assert_greater_or_equals(a, b) \
  coal_testing_assert(coal_base_Object_cmp((a), (b)) >= 0)

/**
 * coal_testing_assert_inequals
 *
 * Asserts that two objects are inequal.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_testing_assert_inequals(a, b) \
  coal_testing_assert(!coal_base_Object_equals((a), (b)))

/**
 * coal_testing_assert_less
 *
 * Asserts that one object is less than another object.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_testing_assert_less(a, b) \
  coal_testing_assert(coal_base_Object_cmp((a), (b)) < 0)

/**
 * coal_testing_assert_less_or_equals
 *
 * Asserts that one object is less than or equal to another
 * object.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_testing_assert_less_or_equals(a, b) \
  coal_testing_assert(coal_base_Object_cmp((a), (b)) <= 0)

/**
 * coal_testing_non_null
 *
 * Asserts that a pointer is not NULL.
 *
 * @param  (void *) pointer
 */
#define coal_testing_assert_non_null(ptr) \
  coal_testing_assert((ptr) != NULL)

/**
 * coal_testing_assert_null
 *
 * Asserts that a pointer is NULL.
 *
 * @param  (void *) pointer
 */
#define coal_testing_assert_null(ptr) \
  coal_testing_assert((ptr) == NULL)

#ifdef COAL_TESTING_NAMESPACE_POLLUTE
# define assert(cond)                   coal_testing_assert(cond)
# define assert_equals(a, b)            coal_testing_assert_equals(a, b)
# define assert_greater(a, b)           coal_testing_assert_greater(a, b)
# define assert_greater_or_equals(a, b) coal_testing_assert_greater_or_equals(a, b)
# define assert_inequals(a, b)          coal_testing_assert_inequals(a, b)
# define assert_less(a, b)              coal_testing_assert_less(a, b)
# define assert_less_or_equals(a, b)    coal_testing_assert_less_or_equals(a, b)
# define assert_non_null(ptr)           coal_testing_assert_non_null(ptr)
# define assert_null(ptr)               coal_testing_assert_null(ptr)
#endif

#endif /* COAL_TESTING_ASSERT_H */

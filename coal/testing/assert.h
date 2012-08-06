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

#include <coal/private/branching.h>
#include <coal/private/preprocessor.h>

#include <coal/base/Object.h>
#include <coal/testing/AssertionError.h>

/**
 * coal_assert
 *
 * Asserts that a condition is true and throws an
 * AssertionError if it is not.
 *
 * @param  (cond) boolean condition
 */
#define coal_assert(cond)				  \
  do {							  \
    if (unlikely(!(cond)))				  \
      coal_throw(coal_new(coal_testing_AssertionError(),  \
			  "file: %s, function: %s, "	  \
			  "line: %d, condition: "	  \
			  STRINGIFY_EXPANSION(cond),	  \
			  __FILE__, __func__, __LINE__)); \
  } while (0)

/**
 * coal_assert_equals
 *
 * Asserts that two objects are equal.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_assert_equals(a, b) \
  coal_assert(coal_base_Object_equals((a), (b)))

/**
 * coal_assert_inequals
 *
 * Asserts that two objects are inequal.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_assert_inequals(a, b) \
  coal_assert(!coal_base_Object_equals((a), (b)))

/**
 * coal_assert_less
 *
 * Asserts that one object is less than another object.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_assert_less(a, b) \
  coal_assert(coal_base_Object_cmp((a), (b)) < 0)

/**
 * coal_assert_less_or_equals
 *
 * Asserts that one object is less than or equal to another
 * object.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_assert_less_or_equals(a, b) \
  coal_assert(coal_base_Object_cmp((a), (b)) <= 0)

/**
 * coal_assert_greater
 *
 * Asserts that one object is greater than another object.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_assert_greater(a, b) \
  coal_assert(coal_base_Object_cmp((a), (b)) > 0)

/**
 * coal_assert_greater_or_equals
 *
 * Asserts that one object is greater than or equal to
 * another object.
 *
 * @param  (val) first object
 * @param  (val) second object
 */
#define coal_assert_greater_or_equals(a, b) \
  coal_assert(coal_base_Object_cmp((a), (b)) >= 0)

#endif /* COAL_TESTING_ASSERT_H */

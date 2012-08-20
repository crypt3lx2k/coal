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

#ifndef COAL_COLLECTIONS_ITERABLE_H
#define COAL_COLLECTIONS_ITERABLE_H

#include <coal/base/Metaclass.h>

/**
 * coal_collections_Iterable
 *
 * Metaclass for iterables.
 *
 * @extends coal_base_Metaclass
 * @constructor takes 10 arguments
 * @param (const char *) name of class
 * @param (const class(Metaclass) *) super class
 * @param (size_t) size of instances of this class in bytes
 * @param (int (*cmp)(val, val)) pointer to comparator function
 * @param (var (*constructor)(var, va_list *)) pointer to constructor
 * @param (var (*destructor)(var)) pointer to destructor
 * @param (bool (*equals)(val, val)) pointer to equality function
 * @param (int (*hashCode)(val)) pointer to hash function
 * @param (var (*toString)(val)) pointer to string representation function
 * @param (var (*iterator)(val)) pointer to function that returns iterator for the object
 */
coal_cfunspec val coal_collections_Iterable (void) coal_funattr_const;

/**
 * coal_collections_Iterable_iterator
 *
 * Returns an iterator for the iterable object.
 *
 * @param  (val) iterable
 * @return (var) iterator
 */
coal_cfunspec var coal_collections_Iterable_iterator (val self);

#ifdef COAL_COLLECTIONS_NAMESPACE_POLLUTE
# define Iterable()           coal_collections_Iterable()
# define Iterable_iterator(s) coal_collections_Iterable_iterator(s)
#endif

#ifdef COAL_COLLECTIONS_ITERABLE_NAMESPACE_POLLUTE
# define iterator(s) coal_collections_Iterable_iterator(s)
#endif

#endif /* COAL_COLLECTIONS_ITERABLE_H */

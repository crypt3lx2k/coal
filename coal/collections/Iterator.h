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

#ifndef COAL_COLLECTIONS_ITERATOR_H
#define COAL_COLLECTIONS_ITERATOR_H

#include <coal/base/Metaclass.h>

/**
 * coal_collections_Iterator
 *
 * Metaclass for iterators.
 *
 * @extends coal_base_Metaclass
 * @constructor takes 11 arguments
 * @param (const char *) name of class
 * @param (const class(Metaclass) *) super class
 * @param (size_t) size of instances of this class in bytes
 * @param (int (*cmp)(val, val)) pointer to comparator function
 * @param (var (*constructor)(var, va_list *)) pointer to constructor
 * @param (var (*destructor)(var)) pointer to destructor
 * @param (bool (*equals)(val, val)) pointer to equality function
 * @param (int (*hashCode)(val)) pointer to hash function
 * @param (var (*toString)(val)) pointer to string representation function
 * @param (bool (*hasNext)(val)) pointer to function which returns if there are more elements to iterate over
 * @param (val (*next)(var)) pointer to function which returns the next element to iterate over
 */
coal_cfunspec val coal_collections_Iterator (void) coal_funattr_const;

/**
 * coal_collections_Iterator_hasNext
 *
 * Returns whether there are more elements to iterate over.
 *
 * @param  (val) iterator
 * @return (bool) true if there are more elements to iterate over and false otherwise
 */
coal_cfunspec bool coal_collections_Iterator_hasNext (val self);

/**
 * coal_collections_Iterator_next
 *
 * Returns the next element in the iteration.
 *
 * @param  (var) self
 * @param  (val) next element in the iteration
 */
coal_cfunspec val coal_collections_Iterator_next (var self);

#ifdef COAL_COLLECTIONS_NAMESPACE_POLLUTE
# define Iterator()          coal_collections_Iterator()
# define Iterator_hasNext(s) coal_collections_Iterator_hasNext(s)
# define Iterator_next(s)    coal_collections_Iterator_next(s)
#endif

#ifdef COAL_COLLECTIONS_ITERATOR_NAMESPACE_POLLUTE
# define hasNext(s) coal_collections_Iterator_hasNext(s)
# define next(s)    coal_collections_Iterator_next(s)
#endif

#endif /* COAL_COLLECTIONS_ITERATOR_H */

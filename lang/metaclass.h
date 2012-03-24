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

#ifndef COAL_LANG_METACLASS_H__
#define COAL_LANG_METACLASS_H__

#include <coal/coal.h>

/**
 * coal_lang_metaclass
 * Base class for, well, classes.
 *
 * @extends coal_lang_object
 * @constructor takes 9 arguments
 * @param (const char *) name of class
 * @param (const class(metaclass) *) super class
 * @param (size_t) size of instances in bytes
 * @param (int (*cmp)(const var, const var)) pointer to comparison function
 * @param (var (*constructor)(var, va_list *)) pointer to constructor
 * @param (var (*destructor)(var)) pointer to destructor
 * @param (bool (*equals)(const var, const var)) pointer to equality function
 * @param (int (*hashCode)(const var)) pointer to hash function
 * @param (var (*toString)(const var)) pointer to string function
 */
cfundecl__ (const var coal_lang_metaclass (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define metaclass coal_lang_metaclass
#endif

#endif /* COAL_LANG_METACLASS_H__ */

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

#ifndef COAL_OBJECT_ORIENTATION_H__
#define COAL_OBJECT_ORIENTATION_H__

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/object_orientation.h> directly; use <coal/core/implementation.h> instead."
#endif

/* this is here in case of
   change in the future */
#define class(name) struct name

#define extends(name) const class(name) name##__

/**
 * INHERIT_METHOD
 * Tags a method for inheritance.
 */
#define INHERIT_METHOD 0

/**
 * ABSTRACT_METHOD
 * Tags a method for being abstract.
 */
#define ABSTRACT_METHOD 1

#endif /* COAL_OBJECT_ORIENTATION_H__ */

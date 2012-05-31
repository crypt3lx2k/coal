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

#ifndef COAL_BASE_METACLASS_H
#define COAL_BASE_METACLASS_H

#include <coal/coal.h>
#include <coal/base/Object.h>

/**
 * coal_base_MetaClass
 *
 * Root of the entire coal interface hierarchy.
 *
 * @extends coal_base_Object
 * @constructor takes an unknown amount of arguments (whelp!)
 */
coal_cfunspec val coal_base_MetaClass (void) coal_funattr_const;

#ifndef COAL_BASE_NAMESPACE_POLLUTE
# define MetaClass() coal_base_MetaClass()
#endif

#endif /* COAL_BASE_METACLASS_H */

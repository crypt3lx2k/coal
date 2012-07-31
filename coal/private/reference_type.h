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

#ifndef COAL_PRIVATE_REFERENCE_TYPE_H
#define COAL_PRIVATE_REFERENCE_TYPE_H

#include <coal/private/atomic.h>

/* we have to put this in a file of its own to avoid cyclic
   inclusion between base/Object/Object.rep and
   private/reference_counting.h, this normally wouldn't be
   a problem due to include guards but it really messes with
   the makefile code generator which assumes that the include
   tree is a directed acyclic graph, emphasis on the acyclic */
typedef atomic(unsigned int) refcnt_type;

#endif /* COAL_PRIVATE_REFERENCE_TYPE_H */

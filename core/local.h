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

#ifndef COAL_CORE_LOCAL_H__
#define COAL_CORE_LOCAL_H__

#include <coal/coal.h>

/**
 * coal_core_collector
 * Calls del on the object pointed to.
 * Needed to implement the coal_local macro.
 *
 * @param (var *) pointer to object that is to be deleted
 */
cfundecl__ (void coal_core_collector (var * ptr));

/* tags a variable to be collected upon
   going out of scope */
/* in case it isn't obvious, don't use this */
#define coal_local __attribute__ ((cleanup(coal_core_collector)))

#endif /* COAL_CORE_LOCAL_H__ */

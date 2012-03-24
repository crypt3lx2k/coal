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

#ifndef COAL_CORE_CDEFS_H__
#define COAL_CORE_CDEFS_H__

/* this is here in case we
   need to change how every
   function is declared
   in the future */
#define cfundecl__(cfundecl) \
  extern inline cfundecl

/**
 * Object variable type
 */
/* not a typedef so `const var'
   behaves nicely */
#define var void *

#endif /* COAL_CORE_CDEFS_H__ */

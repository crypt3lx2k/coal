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

#ifndef COAL_PRIVATE_COLLECTED_H
#define COAL_PRIVATE_COLLECTED_H

#include <coal/private/cdefs.h>

/**
 * coal_private_collector
 *
 * Calls del on the object pointed to.
 *
 * @param  (var *) pointer to object that is to be deleted
 */
coal_cfunspec void coal_private_collector (var * ptr);

#ifdef __GNUC__
# define coal_varattr_collected \
  __attribute__ ((cleanup(coal_private_collector)))
#else
# warning "coal/private/collected.h included without compiler support for automatically cleaned variables, you may not break out of a coal_foreach block"
# define coal_varattr_collected
#endif /* __GNUC__ */

#endif /* COAL_PRIVATE_COLLECTED_H */

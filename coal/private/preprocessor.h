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

#ifndef COAL_PRIVATE_PREPROCESSOR_H
#define COAL_PRIVATE_PREPROCESSOR_H

/* keep this header clean for users, might be installed */

#define COAL_STRINGIFY(m) #m
#define COAL_STRINGIFY_EXPANSION(m) COAL_STRINGIFY(m)

#define COAL_CONCATENATE(m, n) m ## n
#define COAL_CONCATENATE_EXPANSION(m, n) \
  COAL_CONCATENATE(m, n)

#endif /* COAL_PRIVATE_PREPROCESSOR_H */

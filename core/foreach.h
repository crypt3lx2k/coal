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

#ifndef COAL_CORE_FOREACH_H__
#define COAL_CORE_FOREACH_H__

#include <coal/lang/iterable.h>
#include <coal/util/iterator.h>

#include <coal/core/local.h>

#define foreach(v, i)                                           \
  ({                                                            \
    var foreach_iter__ coal_local;                              \
    for (foreach_iter__ = coal_lang_iterable_iterator(i);       \
         coal_util_iterator_hasNext(foreach_iter__); ) {        \
      v = coal_util_iterator_next(foreach_iter__);

#define foreach_end                             \
    }                                           \
  })

#endif /* COAL_CORE_FOREACH_H__ */

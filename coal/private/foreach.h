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

#ifndef COAL_PRIVATE_FOREACH_H
#define COAL_PRIVATE_FOREACH_H

/* keep this header clean for users, might be installed */

#include <coal/private/cdefs.h>
#include <coal/private/collected.h>

#include <coal/collections/Iterable.h>
#include <coal/collections/Iterator.h>

#define coal_foreach(v, i)                              \
  do {                                                  \
    var _coal_private_foreach_i coal_varattr_collected; \
    for (_coal_private_foreach_i =                      \
           coal_collections_Iterable_iterator(i);       \
         coal_collections_Iterator_hasNext(             \
           _coal_private_foreach_i                      \
         );                                             \
        ) {                                             \
      v = coal_collections_Iterator_next(               \
            _coal_private_foreach_i                     \
          );

#ifdef __GNUC__
/* collected version */
# define coal_foreach_end                               \
    }                                                   \
  } while (0)
#else
/* uncollected version */
# define coal_foreach_end                               \
    }                                                   \
    coal_del(_coal_private_foreach_i);                  \
  } while (0)
#endif /* __GNUC__ */

#endif /* COAL_PRIVATE_FOREACH_H */

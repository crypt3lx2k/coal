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

#ifndef COAL_TRY_CATCH_H
#define COAL_TRY_CATCH_H

#include <coal/private/try_catch.h>

#ifdef COAL_NAMESPACE_POLLUTE
# define catch(e, i) coal_catch(e, i)
# define finally     coal_finally
# define rethrow()   coal_rethrow()
# define try         coal_try
# define try_end     coal_try_end
#endif /* COAL_NAMESPACE_POLLUTE */

#endif /* COAL_TRY_CATCH_H */

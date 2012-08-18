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

#ifndef COAL_ABSTRACT_ABSTRACTINSTANTIATIONERROR_H
#define COAL_ABSTRACT_ABSTRACTINSTANTIATIONERROR_H

#include <coal/abstract/AbstractError.h>

/**
 * coal_abstract_AbstractInstantiationError
 *
 * Error that indicates that an attempt was made to
 * instantiate an abstract class.
 *
 * @extends coal_abstract_AbstractError
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
coal_cfunspec val coal_abstract_AbstractInstantiationError (void) coal_funattr_const;

#ifdef COAL_ABSTRACT_NAMESPACE_POLLUTE
# define AbstractInstantiationError() coal_error_AbstractInstantiationError()
#endif

#endif /* COAL_ABSTRACT_ABSTRACTINSTANTIATIONERROR_H */

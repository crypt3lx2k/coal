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

#ifndef COAL_ERROR_OUTOFMEMORYERROR_H
#define COAL_ERROR_OUTOFMEMORYERROR_H

#include <coal/error/Error.h>

/**
 * coal_error_OutOfMemoryError
 *
 * Error that indicates that the implementation made a request
 * for resources that was either erroneous or unfulfilled.
 *
 * @extends coal_error_Error
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
coal_cfunspec val coal_error_OutOfMemoryError (void) coal_funattr_const;

#ifdef COAL_ERROR_NAMESPACE_POLLUTE
# define OutOfMemoryError() coal_error_OutOfMemoryError()
#endif

#endif /* COAL_ERROR_OUTOFMEMORYERROR_H */

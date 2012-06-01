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

#ifndef COAL_ERROR_ILLEGALSTATEEXCEPTION_H
#define COAL_ERROR_ILLEGALSTATEEXCEPTION_H

#include <coal/error/Exception.h>

/**
 * coal_error_IllegalStateException
 *
 * Exception that indicates an attempt was made
 * to mutate an object in such a manner that the
 * new state would become invalid or illegal.
 *
 * @extends coal_error_Exception
 * @constructor takes a variable amount of arguments
 * @param (const char *) printf-like format string
 * @param (...) printf-like arguments
 */
coal_cfunspec val coal_error_IllegalStateException (void) coal_funattr_const;

#ifdef COAL_ERROR_NAMESPACE_POLLUTE
# define IllegalStateException() coal_error_IllegalStateException()
#endif

#endif /* COAL_ERROR_ILLEGALSTATEEXCEPTION_H */

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

#ifndef COAL_PRIVATE_CLASSES_SUBCLASS_H
#define COAL_PRIVATE_CLASSES_SUBCLASS_H

#include <coal/private/object_orientation.h>
#include <coal/base/Metaclass.h>

/**
 * coal_private_Subclass
 *
 * Takes a metaclass and subclasses it without overriding
 * anything. This is useful for defining small class
 * hierarchies (like the exception hierarchy) quickly.
 *
 * @extends coal_base_Metaclass
 * @constructor takes 2 arguments
 * @param (const char *) name of new class
 * @param (val) class to extend
 */
coal_cfunspec val coal_private_Subclass (void) coal_funattr_const;

/* boilerplate for defining
   new exceptions in the
   exception hierarchy */
#define ExceptionDefinitionTemplate(name, string, superclass)   \
  SETUP_CLASS_DESCRIPTION(name,                                 \
                          coal_private_Subclass(),              \
                          string,                               \
                          superclass)

#endif /* COAL_PRIVATE_CLASSES_SUBCLASS_H */

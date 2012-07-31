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

#include <features.h>
#if __GLIBC_PREREQ (2, 10)
/* We either succeed or attempt to silently fail, this
   code is glibc specific and the rest of this library does
   not rely on it, it is safe to remove this file in case it
   fails to compile */

#include <printf.h>
#include <stdarg.h>
#include <string.h>

#include <coal/base/Object.h>
#include <coal/io/io.h>

static int pt_obj;

static void coal_obj_va (void * mem, va_list * ap) {
  val o = va_arg(*ap, val);
  memcpy(mem, &o, sizeof(o));
}

static int coal_obj_ais (const struct printf_info * info coal_attr_unused,
			 size_t n coal_attr_unused,
			 int * argtype,
			 int * size) {
  argtype[0] = pt_obj;
  size[0] = sizeof(val);
  return 1;
}

static int coal_obj_printf (FILE * fp,
			    const struct printf_info * info coal_attr_unused,
			    const void * const * args) {
  val o;

  memcpy(&o, *((void ***) args)[0], sizeof(o));

  return coal_io_fprint(o, fp);
}

static void coal_obj_printf_startup (void)
  __attribute__ ((constructor));

static void coal_obj_printf_startup (void) {
  pt_obj = register_printf_type(coal_obj_va);
  register_printf_specifier('O', coal_obj_printf,
			    coal_obj_ais);
}

#endif /* GLIBC version 2.10 or newer */

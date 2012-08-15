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

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h> /* abort */

#if HAVE_EXECINFO_H
# include <execinfo.h>
# include <unistd.h>
#endif /* HAVE_EXECINFO_H */

#include <coal/io/io.h>

#include <coal/private/stack.h>
#include <coal/private/try_catch.h>

noreturn void coal_throw (var throwable) {
  if (coal_private_stack_isEmpty(&_coal_private_try_stack)) {
    fputs("unhandled exception: ", stderr);
    coal_io_fprintln(throwable, stderr);

#if HAVE_EXECINFO_H
    {
      void * backtrace_buffer[100];

      fputs("Backtrace:\n", stderr);
      backtrace_symbols_fd(backtrace_buffer,
			   backtrace(backtrace_buffer, 100),
			   STDERR_FILENO);
    }
#endif /* HAVE_EXECINFO_H */

    coal_del(throwable);
    exit(EXIT_FAILURE);
  } else {
    struct _coal_private_try_context * handler =
      coal_private_stack_pop(&_coal_private_try_stack);

    /* this will never happen, look up */
    if (handler == NULL) {
      fputs("fatal exception stack error: No such element\n",
	    stderr);
      abort();
    }

    handler->object = throwable;
    longjmp(handler->execbuf, 1);
  }
}

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

#if HAVE_FEATURES_H
# include <features.h>
# if __GLIBC_PREREQ (2, 1) && HAVE_EXECINFO_H
#  include <execinfo.h>
#  include <unistd.h>
#  define HAVE_BACKTRACE 1
# endif /* GLIBC version 2.1 or newer && HAVE_EXECINFO_H */
#endif /* HAVE_FEATURES_H */

#include <coal/private/thread_local.h>
#include <coal/private/try_catch.h>

#include <coal/io/io.h>
#include <coal/parallel/Thread.h> /* coal_parallel_Thread_exit */

#include <coal/private/exception_handling.h>
#include <coal/coal.h>

static thread_local coal_exhandler_fn _coal_exhandler_current = COAL_EX_DFL;

coal_exhandler_fn coal_exhandler_set (coal_exhandler_fn func) {
  coal_exhandler_fn old;

  old = _coal_exhandler_current;
  _coal_exhandler_current = func;

  return old;
}

noreturn void coal_throw (var throwable) {
  if (coal_private_try_isEmpty()) {
    if (_coal_exhandler_current != COAL_EX_DFL)
      _coal_exhandler_current(throwable);

    fputs("unhandled exception: ", stderr);
    coal_io_fprintln(throwable, stderr);

    fputs("Backtrace:\n", stderr);
#if HAVE_BACKTRACE
    {
      void * backtrace_buffer[100];

      backtrace_symbols_fd(backtrace_buffer,
			   backtrace(backtrace_buffer, 100),
			   STDERR_FILENO);
    }
#else /* ! HAVE_BACKTRACE */
    fputs("(not available)\n", stderr);
#endif /* HAVE_BACKTRACE */

    coal_del(throwable);
    coal_parallel_Thread_exit(NULL);
  } else {
    struct _coal_private_try_context * handler =
      coal_private_try_pop();

    /* this will never happen, stack isn't empty */
    if (handler == NULL) {
      fputs("fatal exception stack error: No such element\n",
	    stderr);
      abort();
    }

    handler->object = throwable;
    longjmp(handler->execbuf, 1);
  }
}

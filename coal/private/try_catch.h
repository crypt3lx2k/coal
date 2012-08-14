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

#ifndef COAL_PRIVATE_TRY_CATCH_H
#define COAL_PRIVATE_TRY_CATCH_H

/* keep this header clean for users, might be installed */

#include <setjmp.h>
#include <stdbool.h>

#include <coal/private/cdefs.h>
#include <coal/private/stack.h>
#include <coal/private/thread_local.h>

#include <coal/coal.h>

extern thread_local struct coal_private_stack _coal_private_try_stack;

struct _coal_private_try_context {
  jmp_buf execbuf;
  var object;
};

#define coal_try                                          \
  do {                                                    \
    struct _coal_private_try_context _coal_private_try_c; \
    bool _coal_private_try_caught = false;                \
    int _coal_private_try_setjmp_result;                  \
                                                          \
    coal_private_stack_push(&_coal_private_try_stack,     \
                            &_coal_private_try_c);        \
                                                          \
    if (! (_coal_private_try_setjmp_result =              \
           setjmp(_coal_private_try_c.execbuf))) {

#define coal_catch(exception, identifier)                \
    }                                                    \
    else if (coal_instanceof(_coal_private_try_c.object, \
                             exception)) {               \
      var identifier = _coal_private_try_c.object;       \
      _coal_private_try_caught = true;

#define coal_try_end                                      \
    }                                                     \
    if (! _coal_private_try_setjmp_result) {              \
      /* nothing went wrong, we pop our handler */        \
      (void)                                              \
        coal_private_stack_pop(&_coal_private_try_stack); \
    } else if (! _coal_private_try_caught) {              \
      /* something went wrong (so handler is popped) */   \
      /* also we didn't catch so pass it on */            \
      coal_throw(_coal_private_try_c.object);             \
    } else {                                              \
      /* something went wrong (so handler is popped) */   \
      /* we did catch so delete exception */              \
      coal_del(_coal_private_try_c.object);               \
    }                                                     \
  } while (0)

#endif /* COAL_PRIVATE_TRY_CATCH_H */

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

#include <coal/coal.h>

struct _coal_private_try_context {
  jmp_buf execbuf;
  var object;
};

/* these functions are a window into the thread local
   exception stack, the reason we do not expose the stack
   itself is because that would require the end user to use a
   compiler that supports thread local variables. */

/**
 * coal_private_try_isEmpty
 *
 * Returns whether the thread local exception stack is empty.
 *
 * @return (bool) if the exception stack is empty
 */
coal_cfunspec bool coal_private_try_isEmpty (void);

/**
 * coal_private_try_pop
 *
 * Pops the exception context off the top of the thread local
 * exception stack.
 *
 * This function returns NULL if no such exception context
 * exists.
 *
 * @return (struct _coal_private_try_context *) exception context at top of exception stack
 */
coal_cfunspec struct _coal_private_try_context * coal_private_try_pop (void);

/**
 * coal_private_try_push
 *
 * Pushes an exception context on to the top of the thread
 * local exception stack.
 *
 * @param  (struct _coal_private_try_context *) exception context
 */
coal_cfunspec void coal_private_try_push (struct _coal_private_try_context * c);

#define coal_try                                          \
  do {                                                    \
    struct _coal_private_try_context _coal_private_try_c; \
    bool _coal_private_try_caught = false;                \
    int _coal_private_try_setjmp_result;                  \
                                                          \
    coal_private_try_push(&_coal_private_try_c);          \
                                                          \
    if (! (_coal_private_try_setjmp_result =              \
           setjmp(_coal_private_try_c.execbuf))) {

#define coal_catch(exception, identifier)                 \
    }                                                     \
    else if (coal_instanceof(_coal_private_try_c.object,  \
                             exception)) {                \
      var identifier = _coal_private_try_c.object;        \
      _coal_private_try_caught = true;

#define coal_rethrow()                                    \
      _coal_private_try_caught = false

#define coal_finally                                      \
    } {

#define coal_try_end                                      \
    }                                                     \
    if (! _coal_private_try_setjmp_result) {              \
      /* nothing went wrong, we pop our handler */        \
      (void) coal_private_try_pop();                      \
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

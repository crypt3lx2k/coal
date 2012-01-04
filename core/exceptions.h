#ifndef COAL_CORE_EXCEPTIONS_H__
#define COAL_CORE_EXCEPTIONS_H__

#include <setjmp.h>
#include <coal/core/utility_stack.h>

#if !(defined COAL_CORE_IMPLEMENTATION_H__ || \
      defined COAL_USER_EXCEPTIONS)
# error "Never include <coal/core/exceptions.h> directly; use <coal/core/implementation.h> instead."
#endif

named_utility_stack(exceptions_stack__, void *);
extern struct exceptions_stack__ exceptions_s__;

#define try                                                             \
  ({                                                                    \
    jmp_buf exceptions_jmp_buf__;                                       \
    var     exceptions_res__;                                           \
    bool    exceptions_caught__ = false;                                \
                                                                        \
    if (! (exceptions_res__ =                                           \
           (var) setjmp(utility_stack_push(&exceptions_s__,             \
                                           &exceptions_jmp_buf__))      \
           )) {

#define catch(exception, identifier)                                    \
  }                                                                     \
  else if (coal_instanceof(exceptions_res__, exception)) {              \
    var identifier = exceptions_res__;                                  \
    exceptions_caught__ = true;

#define finally                                 \
    } {

#define try_end                                         \
    }                                                   \
    (void) utility_stack_pop(&exceptions_s__);          \
    if (exceptions_res__ && ! exceptions_caught__)      \
      coal_throw(exceptions_res__);                     \
    else                                                \
      coal_del(exceptions_res__);                       \
  })

#endif /* COAL_CORE_EXCEPTIONS_H__ */

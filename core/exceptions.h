#ifndef COAL_CORE_EXCEPTIONS_H__
#define COAL_CORE_EXCEPTIONS_H__

#include <setjmp.h>
#include <coal/core/utility_stack.h>

#if !(defined COAL_IMPLEMENTATION_H__ || \
      defined COAL_USER_EXCEPTIONS)
# error "Never include <coal/core/exceptions.h> directly; use <coal/implementation.h> instead."
#endif

named_utility_stack(exceptions_stack__, void *);

extern struct exceptions_stack__ exceptions_s__;

/*
 * These might be in user space.
 */
#ifdef LIB_NAMESPACE_POLLUTE
# define EXCEPTIONS_INSTANCEOF instanceof
# define EXCEPTIONS_THROW      throw
# define EXCEPTIONS_DEL        del
#else /* not LIB_NAMESPACE_POLLUTE */
# define EXCEPTIONS_INSTANCEOF lib(instanceof)
# define EXCEPTIONS_THROW      lib(throw)
# define EXCEPTIONS_DEL        lib(del)
#endif /* LIB_NAMESPACE_POLLUTE */

#define try								\
  ({									\
    jmp_buf exceptions_jmp_buf__;					\
    var     exceptions_res__;						\
    bool    exceptions_caught__ = false;				\
									\
    if (! (exceptions_res__ =						\
	   (var) setjmp(utility_stack_push(&exceptions_s__,		\
					   (void *)			\
					   exceptions_jmp_buf__))	\
	   )) {

#define catch(exception, identifier)					\
  }									\
  else if (EXCEPTIONS_INSTANCEOF(exceptions_res__, exception)) {	\
    var identifier = exceptions_res__;					\
    exceptions_caught__ = true;

#define finally					\
    } {

#define try_end						\
    }							\
    (void) utility_stack_pop(&exceptions_s__);		\
    if (exceptions_res__ && ! exceptions_caught__)	\
      EXCEPTIONS_THROW(exceptions_res__);		\
    else						\
      EXCEPTIONS_DEL(exceptions_res__);			\
  })

#endif /* COAL_CORE_EXCEPTIONS_H__ */

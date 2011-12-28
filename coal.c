#include <setjmp.h>
#include <stdlib.h>

/* for throw */
#include <stdio.h>    /* fputs, fprintf */
#include <unistd.h>   /* STDERR_FILENO */
#include <execinfo.h> /* backtrace* */

#include <coal/core/implementation.h>
#include <coal/lang/NullPointerException.h>

/* for throw */
#include <coal/io/io.h>

var lib(acquire) (var object) {
  return INCREMENT_REFERENCE_COUNT(object);
}

void lib(del) (var object) {
  if (object == NULL)
    return;

  DECREMENT_REFERENCE_COUNT(object);

  if (IS_GARBAGE(object))
    free(lang(destructor)(object));
}

bool lib(instanceof) (const var object, const var class) {
  const class(metaclass) * current = lang(getClass)(object);

  if (current == class)
    return true;

  do {
    current = current->super;

    if (current == class)
      return true;
  } while (current != lang(object)());

  return false;
}

var lib(new) (const var _class, ...) {
  const class(metaclass) * class = _class;
  class(object) * object;
  va_list ap;

  if (class == NULL)
    lib(throw)(lib(new)(lang(NullPointerException)(),
			"lib(new): null class description"));

  object = core(malloc)(class->size);
  object->class = class;

  va_start(ap, _class);
  object = lang(constructor)(object, &ap);
  va_end(ap);

  return lib(acquire(object));
}

void lib(throw) (const var throwable) {
  if (utility_stack_is_empty(&exceptions_s__)) {
    void * backtrace_buffer[100];

    fputs("unhandled exception ", stderr);
    io(fprintln)(throwable, stderr);

    fprintf(stderr,
	    "Backtrace:\n");

    backtrace_symbols_fd(backtrace_buffer,
			 backtrace(backtrace_buffer, 100),
			 STDERR_FILENO);

    exit(EXIT_FAILURE);
  } else {
    longjmp(*(jmp_buf *)
	    utility_stack_peek(&exceptions_s__),
	    (int) throwable);
  }
}

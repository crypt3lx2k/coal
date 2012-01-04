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

var coal_acquire (var object) {
  return INCREMENT_REFERENCE_COUNT(object);
}

void coal_del (var object) {
  if (object == NULL)
    return;

  DECREMENT_REFERENCE_COUNT(object);

  /* what if object is acquired
     by another thread here? */

  if (IS_GARBAGE(object))
    free(coal_lang_destructor(object));
}

bool coal_instanceof (const var object, const var class) {
  const class(metaclass) * current;

  if (class == NULL)
    coal_throw(coal_new(coal_lang_NullPointerException(),
			"coal_instanceof: null class description"));

  current = coal_lang_getClass(object);

  if (current == class)
    return true;

  do {
    current = current->super;

    if (current == class)
      return true;
  } while (current != coal_lang_object());

  return false;
}

var coal_new (const var _class, ...) {
  const class(metaclass) * class = _class;
  class(object) * object;
  va_list ap;

  if (class == NULL)
    coal_throw(coal_new(coal_lang_NullPointerException(),
			"coal_new: null class description"));

  object = coal_core_malloc(class->size);
  object->class = class;
  object->reference_count = 0;

  va_start(ap, _class);
  object = coal_lang_constructor(object, &ap);
  va_end(ap);

  return coal_acquire(object);
}

void coal_throw (const var throwable) {
  if (utility_stack_is_empty(&exceptions_s__)) {
    fputs("unhandled exception ", stderr);
    coal_io_fprintln(throwable, stderr);

    /* glibc specific */
    {
      void * backtrace_buffer[100];

      fprintf(stderr,
	      "Backtrace:\n");

      backtrace_symbols_fd(backtrace_buffer,
			   backtrace(backtrace_buffer, 100),
			   STDERR_FILENO);
    }

    exit(EXIT_FAILURE);
  } else {
    longjmp(*(jmp_buf *)
	    utility_stack_peek(&exceptions_s__),
	    (int) throwable);
  }
}

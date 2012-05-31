#ifndef COAL_PRIVATE_VIRTUAL_METHODS_H
#define COAL_PRIVATE_VIRTUAL_METHODS_H

#include <stdarg.h>

typedef void (*vfunptr)();

/**
 * INHERIT_METHOD
 *
 * Tags a method for inheritance.
 */
#define INHERIT_METHOD ((vfunptr) 0)

/* overrides a method in a class description */
#define OverrideMethod(self, app, method)       \
  ({                                            \
    __typeof__(self->method) external =         \
      va_arg(*app, __typeof__(self->method));   \
                                                \
    if ((vfunptr) external == INHERIT_METHOD)   \
      ((void) 0);                               \
    else                                        \
      self->method = external;                  \
  })

#endif /* COAL_PRIVATE_VIRTUAL_METHODS_H */

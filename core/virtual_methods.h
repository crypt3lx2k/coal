#ifndef __COAL_CORE_VIRTUAL_METHODS_H
#define __COAL_CORE_VIRTUAL_METHODS_H

#include <coal/core/object_orientation.h>

#ifndef __COAL_IMPLEMENTATION_H
# error "Never include <coal/core/virtual_methods.h> directly; use <coal/implementation.h> instead."
#endif

#include <coal/lang/metaclass/metaclass.r>

/* boilerplate for dynamically linked methods */
#define ClassCallTemplate(method, self, ...)			\
  const class(metaclass) * class = lang(getClass(self));	\
  return class->method(self, ##__VA_ARGS__)

/* overrides a method in a class description */
#define OverrideMethod(self, method)					\
  ({									\
    typeof(self->method) external = va_arg(*app, typeof(self->method));	\
    self->method = external == INHERIT_METHOD ? self->method : external; \
  })

#endif /* __COAL_CORE_VIRTUAL_METHODS_H */

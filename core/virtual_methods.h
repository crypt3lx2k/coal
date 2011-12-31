#ifndef COAL_CORE_VIRTUAL_METHODS_H__
#define COAL_CORE_VIRTUAL_METHODS_H__

#include <coal/core/object_orientation.h>

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/virtual_methods.h> directly; use <coal/core/implementation.h> instead."
#endif

#include <coal/lang/NoSuchMethodException.h>

/* boilerplate for dynamically linked methods */
#define ClassCallTemplate(method, klass, self, ...)             \
  const class(klass) * class = lang(getClass(self));            \
  return class->method(self, ##__VA_ARGS__)

/* overrides a method in a class description */
#define OverrideMethod(self, method)                                    \
  ({                                                                    \
    typeof(self->method) external = va_arg(*app, typeof(self->method)); \
    self->method = external == INHERIT_METHOD ? self->method : external; \
  })

/* boilerplate for throwing an exception
   when a method is missing in an object */
#define CheckAndThrowMissingMethodException(method, self, class)        \
  if (! lib(instanceof)(self, class))                                   \
    lib(throw)(lib(new)(lang(NoSuchMethodException)(),                  \
                        method ": invoked on an unsuitable object"))

#endif /* COAL_CORE_VIRTUAL_METHODS_H__ */

#ifndef COAL_CORE_VIRTUAL_METHODS_H__
#define COAL_CORE_VIRTUAL_METHODS_H__

#include <coal/core/object_orientation.h>

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/virtual_methods.h> directly; use <coal/core/implementation.h> instead."
#endif

#include <coal/lang/NoSuchMethodError.h>

/**
 * coal_core_abstract_method
 * Throws an AbstractMethodException when called.
 */
cfundecl__ (void coal_core_abstract_method ())
  __attribute__ ((noreturn));

/* boilerplate for dynamically linked methods */
#define ClassCallTemplate(method, klass, self, ...)             \
  const class(klass) * class = coal_lang_getClass(self);        \
  return class->method(self, ##__VA_ARGS__)

/* overrides a method in a class description */
#define OverrideMethod(self, method)                            \
  ({                                                            \
    typeof(self->method) external =                             \
      va_arg(*app, typeof(self->method));                       \
                                                                \
    if ((int) external == INHERIT_METHOD)                       \
      self->method = self->method;                              \
    else if ((int) external == ABSTRACT_METHOD)                 \
      self->method =                                            \
        (typeof(self->method)) coal_core_abstract_method;       \
    else                                                        \
      self->method = external;                                  \
  })

/* boilerplate for throwing an exception
   when a method is missing in an object */
#define CheckAndThrowMissingMethodException(method, self, class)        \
  if (! coal_instanceof(self, class))                                   \
    coal_throw(coal_new(coal_lang_NoSuchMethodError(),                  \
                        method ": invoked on an unsuitable object"))

#endif /* COAL_CORE_VIRTUAL_METHODS_H__ */

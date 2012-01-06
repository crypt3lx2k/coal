#ifndef COAL_CORE_COMMON_H__
#define COAL_CORE_COMMON_H__

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/common.h> directly; use <coal/core/implementation.h> instead."
#endif

/**
 * Sets up a class description.
 */
#define SETUP_CLASS_DESCRIPTION(name, ...)      \
  static const var name##__ = NULL;             \
                                                \
  const var name (void) {                       \
    return name##__ != NULL ? name##__ :        \
      (name##__ = coal_new(__VA_ARGS__));       \
  }

#endif /* COAL_CORE_COMMON_H__ */

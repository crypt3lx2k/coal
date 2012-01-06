#ifndef COAL_CORE_COMMON_H__
#define COAL_CORE_COMMON_H__

#include <coal/core/utility_mutex.h>

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/common.h> directly; use <coal/core/implementation.h> instead."
#endif

/**
 * Sets up a class description.
 */
#define SETUP_CLASS_DESCRIPTION(name, ...)      \
  static const var name##__ = NULL;             \
  static utility_mutex name##_##mutex##__ =     \
    utility_mutex_open();                       \
                                                \
  const var name (void) {                       \
    utility_mutex_lock(&name##_##mutex##__);    \
    if (name##__ == NULL)                       \
      name##__ = coal_new(__VA_ARGS__);         \
    utility_mutex_unlock(&name##_##mutex##__);  \
                                                \
    return name##__;                            \
  }

#endif /* COAL_CORE_COMMON_H__ */

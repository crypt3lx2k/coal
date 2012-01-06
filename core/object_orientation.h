#ifndef COAL_OBJECT_ORIENTATION_H__
#define COAL_OBJECT_ORIENTATION_H__

/* for SETUP_CLASS_DESCRIPTION */
#include <pthread.h>

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/object_orientation.h> directly; use <coal/core/implementation.h> instead."
#endif

/* this is here in case of
   change in the future */
#define class(name) struct name

#define extends(name) const class(name) name##__

/**
 * INHERIT_METHOD
 * Tags a method for inheritance.
 */
#define INHERIT_METHOD 0

/**
 * Sets up class description.
 */
#define SETUP_CLASS_DESCRIPTION(name, ...)	\
  static const var name##__ = NULL;		\
  static pthread_mutex_t name##_##mutex##__ =	\
    PTHREAD_MUTEX_INITIALIZER;			\
						\
  const var name (void) {			\
    pthread_mutex_lock(&name##_##mutex##__);	\
    if (name##__ == NULL)			\
      name##__ = coal_new(__VA_ARGS__);		\
    pthread_mutex_unlock(&name##_##mutex##__);	\
						\
    return name##__;				\
  }

#endif /* COAL_OBJECT_ORIENTATION_H__ */

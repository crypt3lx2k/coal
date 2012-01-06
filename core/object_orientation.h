#ifndef COAL_OBJECT_ORIENTATION_H__
#define COAL_OBJECT_ORIENTATION_H__

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
						\
  const var name (void) {			\
    return name##__ != NULL ? name##__ :	\
      (name##__ = coal_new(__VA_ARGS__));	\
  }

#endif /* COAL_OBJECT_ORIENTATION_H__ */

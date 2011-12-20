#ifndef COAL_OBJECT_ORIENTATION_H__
#define COAL_OBJECT_ORIENTATION_H__

#ifndef COAL_IMPLEMENTATION_H__
# error "Never include <coal/core/object_orientation.h> directly; use <coal/implementation.h> instead."
#endif

/* the typedef might go away
   so don't rely on it */
#define class(name)		    \
  struct name

#define extends(name) \
  const class(name) name##__

/**
 * INHERIT_METHOD
 * Tags a method for inheritance.
 */
#define INHERIT_METHOD 0

#endif /* COAL_OBJECT_ORIENTATION_H__ */

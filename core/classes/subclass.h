#ifndef COAL_CORE_CLASSES_SUBCLASS_H__
#define COAL_CORE_CLASSES_SUBCLASS_H__

#include <coal/coal.h>
#include <coal/core/namespace.h>

/**
 * core(subclass)
 * Takes a metaclass and subclasses it without overriding
 * anything. This is useful for defining small class
 * hierarchies (like the exception hierarchy) quickly.
 *
 * @extends lang(metaclass)
 * @constructor takes 2 arguments
 * @param (const char *) name of subclass
 * @param (const var) class to extend
 */
cfundecl__ (const var core(subclass) (void));

/* boilerplate for defining
   new exceptions in the
   exception hierarchy */
#define ExceptionDefinitionTemplate(namespace, location, name, superclass) \
  static const var name##__;                                            \
                                                                        \
  const var namespace(name) (void) {                                    \
    return name##__ ? name##__ :                                        \
      (name##__ = lib(new)(core(subclass)(),                            \
                           location,                                    \
                           superclass()));                              \
  }

#endif /* COAL_CORE_CLASSES_SUBCLASS_H__ */

#ifndef COAL_CORE_CLASSES_SUBCLASS_H__
#define COAL_CORE_CLASSES_SUBCLASS_H__

#include <coal/coal.h>

/**
 * coal_core_subclass
 * Takes a metaclass and subclasses it without overriding
 * anything. This is useful for defining small class
 * hierarchies (like the exception hierarchy) quickly.
 *
 * @extends coal_lang_metaclass
 * @constructor takes 2 arguments
 * @param (const char *) name of subclass
 * @param (const var) class to extend
 */
cfundecl__ (const var coal_core_subclass (void))
  __attribute__ ((const));

/* boilerplate for defining
   new exceptions in the
   exception hierarchy */
#define ExceptionDefinitionTemplate(name, string, superclass)   \
  SETUP_CLASS_DESCRIPTION(name,                                 \
                          coal_core_subclass(),                 \
                          string,                               \
                          superclass)


#endif /* COAL_CORE_CLASSES_SUBCLASS_H__ */

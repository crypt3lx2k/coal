#ifndef COAL_LANG_METACLASS_H__
#define COAL_LANG_METACLASS_H__

#include <coal/coal.h>

/**
 * coal_lang_metaclass
 * Base class for, well, classes.
 *
 * @extends coal_lang_object
 * @constructor takes 9 arguments
 * @param (const char *) name of class
 * @param (const class(metaclass) *) super class
 * @param (size_t) size of instances in bytes
 * @param (intptr_t (*cmp)(const var, const var)) pointer to comparison function
 * @param (var (*constructor)(var, va_list *)) pointer to constructor
 * @param (var (*destructor)(var)) pointer to destructor
 * @param (bool (*equals)(const var, const var)) pointer to equality function
 * @param (intptr_t (*hashCode)(const var)) pointer to hash function
 * @param (var (*toString)(const var)) pointer to string function
 */
cfundecl__ (const var coal_lang_metaclass (void))
  __attribute__ ((const));

#ifdef LANG_NAMESPACE_POLLUTE
# define metaclass coal_lang_metaclass
#endif

#endif /* COAL_LANG_METACLASS_H__ */

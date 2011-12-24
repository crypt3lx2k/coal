#ifndef COAL_LANG_METACLASS_H__
#define COAL_LANG_METACLASS_H__

#include <coal/coal.h>
#include <coal/lang/namespace.h>

/**
 * lang(metaclass)
 * Base class for, well, classes.
 *
 * @constructor takes 9 arguments
 * @param (const char *) name of class
 * @param (const class(metaclass) *) super class
 * @param (size_t) size of instances in bytes
 * @param (int (*cmp)(const var, const var)) pointer to comparison function
 * @param (var (*constructor)(var, va_list *)) pointer to constructor
 * @param (var (*destructor)(var)) pointer to destructor
 * @param (bool (*equals)(const var, const var)) pointer to equality function
 * @param (int (*hashCode)(const var)) pointer to hash function
 * @param (var (*toString)(const var)) pointer to string function
 */
cfundecl__ (const var lang(metaclass) (void));

#ifdef LANG_NAMESPACE_POLLUTE
# define metaclass lang(metaclass)
#endif

#endif /* COAL_LANG_METACLASS_H__ */

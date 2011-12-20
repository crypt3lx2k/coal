#ifndef COAL_LANG_METACLASS_H__
#define COAL_LANG_METACLASS_H__

#include <coal/coal.h>
#include <coal/lang/namespace.h>

/**
 * lang(metaclass)
 * Base class for, well, classes.
 *
 * @constructor takes 8 arguments
 * @param (const char *) name of class
 * @param (const struct metaclass_t *) super class
 * @param (size_t) size of instances in bytes
 * @param (int (*cmp)(const var, const var)) pointer to comparison function
 * @param (var (*constructor)(var, va_list *)) pointer to constructor
 * @param (bool (*equals)(const var, const var)) pointer to equality function
 * @param (int (*hashCode)(const var)) pointer to hash function
 * @param (var (*toString)(const var)) pointer to string function
 */
extern const var lang(metaclass);

#ifdef LANG_NAMESPACE_POLLUTE
# define metaclass lang(metaclass)
#endif

#endif /* COAL_LANG_METACLASS_H__ */

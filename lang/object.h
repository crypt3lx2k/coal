#ifndef COAL_LANG_OBJECT_H__
#define COAL_LANG_OBJECT_H__

#include <coal/coal.h>
#include <coal/lang/namespace.h>

/**
 * lang(object)
 * Base class for objects.
 *
 * @constructor takes no arguments
 */
extern const var lang(object);

/**
 * lang(cmp)
 * Compares two objects, returns an
 * int less than zero, zero or greater than
 * zero if self is found to be less, equal
 * or greater than other respectively.
 *
 * @param  (const var) first object to be compared
 * @param  (const var) second object to be compared
 * @return (int) integer that indicates difference between parameters
 */
cfundecl__ (int lang(cmp), (const var self, const var other));

/**
 * lang(constructor)
 * Initializes object properly, takes a
 * variable argument list with the arguments
 * to the constructor. This is visible to the
 * end user so that in the future you may
 * allocate objects on the stack.
 *
 * @param  (var) object to be initialized
 * @param  (va_list *) list with arguments for the constructor
 * @return (var) the initialized object
 */
cfundecl__ (var lang(constructor), (var self, va_list * app));

/**
 * lang(destructor)
 * Destroys and clears objects properly.
 * This is visible to the end user so that
 * in the future you may allocate objects
 * on the stack.
 *
 * @param  (var) object to be cleared
 * @return (var) the cleared object
 */
cfundecl__ (var lang(destructor), (var self));

/**
 * lang(equals)
 * Checks whether two objects are equal.
 * 
 * @param  (const var) first object to be compared
 * @param  (const var) second object to be compared
 * @return (bool) true if the objects were found to be equal, false otherwise
 */
cfundecl__ (bool lang(equals), (const var self, const var other));

/**
 * lang(getClass)
 * Returns the metaclass that object
 * is an instance of.
 *
 * @param  (const var) instance
 * @return (const var) metaclass of instance
 */
cfundecl__ (const var lang(getClass), (const var self));

/**
 * lang(getSize)
 * Returns the size in bytes of an
 * object in memory.
 *
 * @param  (const var) object to be measured
 * @return (size_t) size of object in bytes
 */
cfundecl__ (size_t lang(getSize), (const var self));

/**
 * lang(hashCode)
 * Returns the hash of an object.
 *
 * @param  (const var) object to be hashed
 * @return (int) hash of object
 */
cfundecl__ (int lang(hashCode), (const var self));

/**
 * lang(toString)
 * Returns a string representation of
 * an object.
 *
 * @param  (const var) object that is to be representated as a string
 * @return (var) string representation of object
 */
cfundecl__ (var lang(toString), (const var self));

#ifdef LANG_NAMESPACE_POLLUTE
# define object      lang(object)
# define cmp         lang(cmp)
# define constructor lang(constructor)
# define destructor  lang(destructor)
# define equals      lang(equals)
# define getClass    lang(getClass)
# define getSize     lang(getSize)
# define hashCode    lang(hashCode)
#endif

#endif /* COAL_LANG_OBJECT_H__ */

#ifndef COAL_LANG_OBJECT_H__
#define COAL_LANG_OBJECT_H__

#include <coal/coal.h>

/**
 * coal_lang_object
 * Base class for objects.
 *
 * @extends coal_lang_object
 * @constructor takes 0 arguments
 */
cfundecl__ (const var coal_lang_object (void))
  __attribute__ ((const));

/**
 * coal_lang_cmp
 * Compares two objects, returns an
 * int less than zero, zero or greater than
 * zero if self is found to be less, equal
 * or greater than other respectively.
 *
 * @param  (const var) first object to be compared
 * @param  (const var) second object to be compared
 * @return (int) integer that indicates difference between parameters
 */
cfundecl__ (int coal_lang_cmp (const var self, const var other));

/**
 * coal_lang_constructor
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
cfundecl__ (var coal_lang_constructor (var self, va_list * app));

/**
 * coal_lang_destructor
 * Destroys and clears objects properly.
 * This is visible to the end user so that
 * in the future you may allocate objects
 * on the stack.
 *
 * @param  (var) object to be cleared
 * @return (var) the cleared object
 */
cfundecl__ (var coal_lang_destructor (var self));

/**
 * coal_lang_equals
 * Checks whether two objects are equal.
 * 
 * @param  (const var) first object to be compared
 * @param  (const var) second object to be compared
 * @return (bool) true if the objects were found to be equal, false otherwise
 */
cfundecl__ (bool coal_lang_equals (const var self, const var other));

/**
 * coal_lang_getClass
 * Returns the metaclass that object
 * is an instance of.
 *
 * @param  (const var) instance
 * @return (const var) metaclass of instance
 */
cfundecl__ (const var coal_lang_getClass (const var self));

/**
 * coal_lang_getSize
 * Returns the size in bytes of an
 * object in memory.
 *
 * @param  (const var) object to be measured
 * @return (size_t) size of object in bytes
 */
cfundecl__ (size_t coal_lang_getSize (const var self));

/**
 * coal_lang_hashCode
 * Returns the hash of an object.
 *
 * @param  (const var) object to be hashed
 * @return (int) hash of object
 */
cfundecl__ (int coal_lang_hashCode (const var self));

/**
 * coal_lang_toString
 * Returns a string representation of
 * an object.
 *
 * @param  (const var) object that is to be representated as a string
 * @return (var) string representation of object
 */
cfundecl__ (var coal_lang_toString (const var self));

#ifdef LANG_NAMESPACE_POLLUTE
# define object      coal_lang_object
# define cmp         coal_lang_cmp
# define constructor coal_lang_constructor
# define destructor  coal_lang_destructor
# define equals      coal_lang_equals
# define getClass    coal_lang_getClass
# define getSize     coal_lang_getSize
# define hashCode    coal_lang_hashCode
# define toString    coal_lang_toString
#endif

#endif /* COAL_LANG_OBJECT_H__ */

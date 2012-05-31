#ifndef COAL_BASE_OBJECT_H
#define COAL_BASE_OBJECT_H

#include <coal/coal.h>

/**
 * coal_base_Object
 *
 * Root of the entire coal class hierarchy.
 *
 * @extends coal_base_Object
 * @constructor takes 0 arguments
 */
coal_cfunspec val coal_base_Object (void) coal_funattr_const;

/**
 * coal_base_Object_cmp
 *
 * Compares this object with another object, returns an int
 * less than zero, zero or greater than zero if self is found
 * to be less, equal or greater than the other object
 * respectively.
 *
 * @param  (val) first object to be compared
 * @param  (val) second object to be compared
 * @return (int) integer that indicates difference between parameters
 */
coal_cfunspec int coal_base_Object_cmp (val self, val other);

/**
 * coal_base_Object_constructor
 *
 * Initializes object properly, takes a variable argument
 * list with the arguments to pass on to the constructor.
 *
 * @param  (var) object to be initialized
 * @param  (va_list) list of arguments to the constructor
 * @return (var) the initialized object
 */
coal_cfunspec var coal_base_Object_constructor (var self, va_list * args);

/**
 * coal_base_Object_destructor
 *
 * Destroys and clears this object properly.
 *
 * @param  (var) object to be cleared
 * @return (var) the cleared object
 */
coal_cfunspec var coal_base_Object_destructor (var self);

/**
 * coal_base_Object_equals
 *
 * Checks whether this object is equal to another object.
 * 
 * @param  (val) first object to be compared
 * @param  (val) second object to be compared
 * @return (bool) true if the objects were found to be equal, false otherwise
 */
coal_cfunspec bool coal_base_Object_equals (val self, val other);

/**
 * coal_base_Object_getClass
 *
 * Returns the class that this object is an instance of.
 *
 * @param  (val) instance
 * @return (val) metaclass of instance
 */
coal_cfunspec val coal_base_Object_getClass (val self);

/**
 * coal_base_Object_getSize
 *
 * Returns the size of this object in bytes.
 *
 * @param  (val) object
 * @return (size_t) size of objects in bytes
 */
coal_cfunspec size_t coal_base_Object_getSize (val self);

/**
 * coal_base_Object_hashCode
 *
 * Returns the hash of this object.
 *
 * @param  (val) object to be hashed
 * @return (int) hash of object
 */
coal_cfunspec int coal_base_Object_hashCode (val self);

/**
 * coal_base_Object_toString
 *
 * Returns a string representation of this object.
 *
 * @param  (val) object that is to be representated as a string
 * @return (var) string representation of object
 */
coal_cfunspec var coal_base_Object_toString (val self);

#ifdef COAL_BASE_NAMESPACE_POLLUTE
# define Object()                 coal_base_Object()
# define Object_cmp(s, o)         coal_base_Object_cmp(s, o)
# define Object_constructor(s, a) coal_base_Object_constructor(s, a)
# define Object_destructor(s)     coal_base_Object_destructor(s)
# define Object_equals(s, o)      coal_base_Object_equals(s, o)
# define Object_getClass(s)       coal_base_Object_getClass(s)
# define Object_getSize(s)        coal_base_Object_getSize(s)
# define Object_hashCode(s)       coal_base_Object_hashCode(s)
# define Object_toString(s)       coal_base_Object_toString(s)
#endif

#ifdef COAL_BASE_OBJECT_NAMESPACE_POLLUTE
# define cmp(s, o)         coal_base_Object_cmp(s, o)
# define constructor(s, a) coal_base_Object_constructor(s, a)
# define destructor(s)     coal_base_Object_destructor(s)
# define equals(s, o)      coal_base_Object_equals(s, o)
# define getClass(s)       coal_base_Object_getClass(s)
# define getSize(s)        coal_base_Object_getSize(s)
# define hashCode(s)       coal_base_Object_hashCode(s)
# define toString(s)       coal_base_Object_toString(s)
#endif

#endif /* COAL_BASE_OBJECT_H */

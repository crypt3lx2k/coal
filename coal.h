#ifndef COAL_H__
#define COAL_H__

#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>

/* this defines cfundecl__ and
   the var datatype. */
#include <coal/core/cdefs.h>

/*
 * Note that defining this macro will expose the user some to
 * of the inner workings of the coal exception system.
 *
 * This is necessary since it is implemented using macros.
 *
 * The system is likely subject to change, don't rely on it.
 * It pollutes the namespace with these symbols.
 *
 * - try
 * - catch
 * - finally
 * - try_end
 * - everything in core/utility_stack.h
 * - everything in stdlib.h
 * - everything in setjmp.h
 */
#ifdef COAL_USER_EXCEPTIONS
# include <coal/core/exceptions.h>
#endif

/* Functions */

/**
 * coal_acquire
 * Increments the reference counter.
 *
 * @param  (var) object which reference counter will be incremented
 * @return (var) object that was passed
 */
cfundecl__ (var coal_acquire (var object));

/**
 * coal_del
 * Decrements the reference counter and
 * collects the object if the count is zero.
 *
 * @param (var) object which reference counter will be decremented and possibly collected 
 */
cfundecl__ (void coal_del (var object));

/**
 * coal_instanceof
 * Determines if the object is an instance
 * of class or any of its subclasses.
 * This means that if an object "o" is instance
 * of a class "klass", then coal_instanceof(o, k)
 * will return true if klass is a subclass of k.
 *
 * coal_instanceof(non_null, object()) - true
 *
 * @param  (const var) object to check type of
 * @param  (class) type to check against
 * @return (bool) true if object is of type class
 */
cfundecl__ (bool coal_instanceof (const var object, const var class));

/**
 * coal_new
 * Creates and returns a new instance of a class.
 *
 * @param  (const var) class to be instantiated
 * @param  (type) arguments to class constructor
 * @return (var) new instance of class
 */
cfundecl__ (var coal_new (const var class, ...)) __attribute__ ((malloc));

/**
 * coal_throw
 * Throws an exception.
 * Currently everything is a valid exception.
 *
 * Note that this function does not return.
 *
 * @param (const var) throwable object
 */
cfundecl__ (void coal_throw (var throwable)) __attribute__ ((noreturn));

/* Functions - end */

#ifdef COAL_NAMESPACE_POLLUTE
# define acquire    coal_acquire
# define del        coal_del
# define new        coal_new
# define instanceof coal_instanceof
# define throw      coal_throw
#endif

#endif /* COAL_H__ */

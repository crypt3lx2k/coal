#ifndef COAL_H__
#define COAL_H__

#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include <coal/namespace.h>

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

/* Types */

/**
 * Object variable type
 */
/* not a typedef so `const var'
   behaves nicely */
#define var void *

/* Types - End */

/* Functions */

/**
 * lib(acquire)
 * Increments the reference counter.
 *
 * @param  (var) object which reference counter will be incremented
 * @return (var) object that was passed
 */
cfundecl__ (var lib(acquire) (var object));

/**
 * lib(del)
 * Decrements the reference counter and
 * collects the object if the count is zero.
 *
 * @param (var) object which reference counter will be decremented and possibly collected 
 */
cfundecl__ (void lib(del) (var object));

/**
 * lib(instanceof)
 * Determines if the object is an instance
 * of class or any of its subclasses.
 * This means that if an object "o" is instance
 * of a class "klass", then lib(instanceof)(o, k)
 * will return true if klass is a subclass of k.
 *
 * lib(instanceof)(non_null, object()) - true
 *
 * @param  (const var) object to check type of
 * @param  (class) type to check against
 * @return (bool) true if object is of type class
 */
cfundecl__ (bool lib(instanceof) (const var object, const var class));

/**
 * lib(new)
 * Creates and returns a new instance of a class.
 *
 * @param  (const var) class to be instantiated
 * @param  (type) arguments to class constructor
 * @return (var) new instance of class
 */
cfundecl__ (var lib(new) (const var class, ...)) __attribute__ ((malloc));

/**
 * lib(throw)
 * Throws an exception.
 * Currently everything is a valid exception.
 *
 * Note that this function does not return.
 *
 * @param (const var) throwable object
 */
cfundecl__ (void lib(throw) (const var throwable)) __attribute__ ((noreturn));

/* Functions - end */

#ifdef LIB_NAMESPACE_POLLUTE
# define acquire    lib(acquire)
# define del        lib(del)
# define new        lib(new)
# define instanceof lib(instanceof)
# define throw      lib(throw)
#endif

#endif /* COAL_H__ */

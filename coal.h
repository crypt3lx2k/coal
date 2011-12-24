#ifndef COAL_H__
#define COAL_H__

#include <stddef.h>
#include <stdarg.h>
#include <coal/namespace.h>

/* Types */

/**
 * Boolean (bool) type
 */
/* TODO: make true and false
   Boolean objects? */
#ifdef __bool_true_false_are_defined
/* use stdbool.h */
# undef true
# undef false

# define true  ((bool) 1)
# define false ((bool) 0)
#else /* not __bool_true_false_are_defined */
/* make our own bool */
typedef enum {
  false = 0,
  true  = 1
} bool;

/* we redefine these so that we may
   use C1x style generic selections
   in the future */
# define true  ((bool) true)
# define false ((bool) false)
#endif /* __bool_true_false_are_defined */

/**
 * Object variable type
 */
/* not a typedef so `const var'
   behaves nicely */
#define var void *

/* TODO: change this to an object? */
#define null ((var) NULL)

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
 * lib(new)
 * Creates and returns a new instance of a class.
 *
 * @param  (const var) class to be instansiated
 * @param  (type) arguments to class constructor
 * @return (var) new instance of class
 */
cfundecl__ (var lib(new) (const var class, ...)) __attribute__ ((malloc));

/* Functions - end */

#ifdef LIB_NAMESPACE_POLLUTE
# define acquire lib(acquire)
# define del     lib(del)
# define new     lib(new)
#endif

#endif /* COAL_H__ */

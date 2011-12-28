#ifndef COAL_CORE_REFERENCE_COUNTING_H__
#define COAL_CORE_REFERENCE_COUNTING_H__

#include <coal/core/atomic.h>

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/reference_counting.h> directly; use <coal/core/implementation.h> instead."
#endif

typedef atomic(unsigned long int) reference_counter_type;

#include <coal/lang/object/object.rep>

/* Don't use these macros, use
   lib(acquire) and lib(del) instead */
/**
 * INCREMENT_REFERENCE_COUNT
 * Increments the reference counter
 * of an object atomically.
 *
 * @param  (var) object in question
 * @return (var) object with increased reference counter
 */
#define INCREMENT_REFERENCE_COUNT(obj)          \
  ({                                            \
    class(object) * o__ = (obj);                \
    atomic_inc(&o__->reference_count);          \
    o__;                                        \
  })

/**
 * DECREMENT_REFERENCE_COUNT
 * Decrements the reference counter
 * of an object atomically.
 *
 * @param  (var) object in question
 * @return (var) object with decremented reference counter
 */
#define DECREMENT_REFERENCE_COUNT(obj)          \
  ({                                            \
    class(object) * o__ = (obj);                \
    atomic_dec(&o__->reference_count);          \
  })

/**
 * IS_GARBAGE
 * Returns whether an object
 * has no remaining references.
 *
 * @param  (var) object in question
 * @return (int) 1 if object's reference counter is 0 and 0 otherwise
 */
#define IS_GARBAGE(obj)                         \
  ({                                            \
    class(object) * o__ = (obj);                \
    o__->reference_count == 0;                  \
  })

#endif /* COAL_CORE_REFERENCE_COUNTING_H__ */

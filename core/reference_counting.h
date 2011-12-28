#ifndef COAL_CORE_REFERENCE_COUNTING_H__
#define COAL_CORE_REFERENCE_COUNTING_H__

#include <coal/core/atomic.h>

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/reference_counting.h> directly; use <coal/core/implementation.h> instead."
#endif

typedef atomic(unsigned long int) reference_counter_type;

#include <coal/lang/object/object.rep>

#define INCREMENT_REFERENCE_COUNT(ident)        \
  ({                                            \
    class(object) * o__ = (ident);              \
    atomic_inc(&o__->reference_count);          \
    o__;                                        \
  })

#define DECREMENT_REFERENCE_COUNT(ident)        \
  ({                                            \
    class(object) * o__ = (ident);              \
    atomic_dec(&o__->reference_count);          \
  })

#define IS_GARBAGE(ident)                       \
  ({                                            \
    class(object) * o__ = (ident);              \
    o__->reference_count == 0;                  \
  })

#endif /* COAL_CORE_REFERENCE_COUNTING_H__ */

#ifndef COAL_CORE_REFERENCE_COUNTING_H__
#define COAL_CORE_REFERENCE_COUNTING_H__

#ifndef COAL_IMPLEMENTATION_H__
# error "Never include <coal/core/reference_counting.h> directly; use <coal/implementation.h> instead."
#endif

typedef unsigned long int reference_counter_type;

#include <coal/lang/object/object.rep>

#define INCREMENT_REFERENCE_COUNT(ident)        \
  ({                                            \
    class(object) * o__ = (ident);              \
    o__->reference_count += 1;                  \
    o__;                                        \
  })

#define DECREMENT_REFERENCE_COUNT(ident)        \
  ({                                            \
    class(object) * o__ = (ident);              \
    o__->reference_count -= 1;                  \
  })

#define IS_GARBAGE(ident)                       \
  ({                                            \
    class(object) * o__ = (ident);              \
    o__->reference_count == 0;                  \
  })

#endif /* COAL_CORE_REFERENCE_COUNTING_H__ */

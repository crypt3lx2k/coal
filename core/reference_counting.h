#ifndef __COAL_CORE_REFERENCE_COUNTING_H
#define __COAL_CORE_REFERENCE_COUNTING_H

#ifndef __COAL_IMPLEMENTATION_H
# error "Never include <coal/core/reference_counting.h> directly; use <coal/implementation.h> instead."
#endif

typedef unsigned long int reference_t;

#define INCREMENT_REFERENCE_COUNT(object)	\
  ({						\
    struct object_t * __o = (object);		\
    __o->reference_count += 1;			\
    __o;					\
  })

#define DECREMENT_REFERENCE_COUNT(object)	\
  ({						\
    struct object_t * __o = (object);		\
    __o->reference_count -= 1;			\
  })

#define IS_GARBAGE(object)			\
  ({						\
    struct object_t * __o = (object);		\
    __o->reference_count == 0;			\
  })

#endif /* __COAL_CORE_REFERENCE_COUNTING_H */

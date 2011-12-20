#ifndef __COAL_CORE_REFERENCE_COUNTING_H
#define __COAL_CORE_REFERENCE_COUNTING_H

#ifndef __COAL_IMPLEMENTATION_H
# error "Never include <coal/core/reference_counting.h> directly; use <coal/implementation.h> instead."
#endif

typedef unsigned long int reference_counter_type;

#include <coal/lang/object/object.r>

#define INCREMENT_REFERENCE_COUNT(ident)	\
  ({						\
    class(object) * __o = (ident);		\
    __o->reference_count += 1;			\
    __o;					\
  })

#define DECREMENT_REFERENCE_COUNT(ident)	\
  ({						\
    class(object) * __o = (ident);		\
    __o->reference_count -= 1;			\
  })

#define IS_GARBAGE(ident)			\
  ({						\
    class(object) * __o = (ident);		\
    __o->reference_count == 0;			\
  })

#endif /* __COAL_CORE_REFERENCE_COUNTING_H */

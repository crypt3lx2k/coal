#ifndef COAL_CORE_FOREACH_H__
#define COAL_CORE_FOREACH_H__

#include <coal/lang/iterable.h>
#include <coal/util/iterator.h>

#include <coal/core/local.h>

#define foreach(v, i)						\
  ({								\
    var foreach_iter__ coal_local;				\
    for (foreach_iter__ = coal_lang_iterable_iterator(i);	\
	 coal_util_iterator_hasNext(foreach_iter__); ) {	\
      v = coal_util_iterator_next(foreach_iter__);

#define foreach_end				\
    }						\
  })

#endif /* COAL_CORE_FOREACH_H__ */

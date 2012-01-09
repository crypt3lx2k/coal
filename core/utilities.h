#ifndef COAL_CORE_UTIL_H__
#define COAL_CORE_UTIL_H__

#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/util.h> directly; use <coal/core/implementation.h> instead."
#endif

/**
 * MAX
 * Returns the greater of
 * two primitive values.
 *
 * @param  (type) first value to compare
 * @param  (type) second value to compare
 * @return (type) greatest value
 */
#define MAX(a, b)                               \
  ({                                            \
    typeof(a) a__ = (a);                        \
    typeof(b) b__ = (b);                        \
                                                \
    a__ < b__ ? b__ : a__;                      \
  })

/**
 * MIN
 * Returns the lesser of
 * two primitive values.
 *
 * @param  (type) first value to compare
 * @param  (type) second value to compare
 * @return (type) lesser value
 */
#define MIN(a, b)                               \
  ({                                            \
    typeof(a) a__ = (a);                        \
    typeof(b) b__ = (b);                        \
                                                \
    a__ < b__ ? a__ : b__;                      \
  })

#endif /* COAL_CORE_UTIL_H__ */

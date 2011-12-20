#ifndef __COAL_LANG_OBJECT_R
#define __COAL_LANG_OBJECT_R

#include <coal/implementation.h>

class (object) {
  const class(metaclass) * class;
  reference_counter_type reference_count;
};

#endif /* __COAL_LANG_OBJECT_R */

#ifndef __COAL_LANG_OBJECT_R
#define __COAL_LANG_OBJECT_R

#include <coal/implementation.h>

class (object) {
  const struct metaclass_t * class;
  reference_t reference_count;
};

#endif /* __COAL_LANG_OBJECT_R */

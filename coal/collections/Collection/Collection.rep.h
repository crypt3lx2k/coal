#ifndef COAL_COLLECTIONS_COLLECTION_REP_H
#define COAL_COLLECTIONS_COLLECTION_REP_H

#include <coal/collections/Iterable/Iterable.rep.h>

class (Collection) {
  extends(Iterable);

  bool (*add)(var self, var element);
  void (*clear)(var self);
  bool (*contains)(val self, val element);
  bool (*isEmpty)(val self);
  bool (*remove)(var self, val element);
  size_t (*size)(val self);
};

#endif /* COAL_COLLECTIONS_COLLECTION_REP_H */

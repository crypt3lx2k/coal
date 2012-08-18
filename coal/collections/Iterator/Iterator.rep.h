#ifndef COAL_COLLECTIONS_ITERATOR_REP_H
#define COAL_COLLECTIONS_ITERATOR_REP_H

#include <coal/base/Metaclass/Metaclass.rep.h>

class (Iterator) {
  extends(Metaclass);

  bool (*hasNext)(val self);
  val (*next)(var self);
};

#endif /* COAL_COLLECTIONS_ITERATOR_REP_H */

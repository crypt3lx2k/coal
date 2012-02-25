#include <coal/core/implementation.h>

void coal_core_collector (var * obj) {
  coal_del(*obj);
}


#ifndef COAL_CORE_LOCAL_H__
#define COAL_CORE_LOCAL_H__

#include <coal/core/memory.h>

#define coal_local __attribute__ ((cleanup(coal_core_collector)))

#endif /* COAL_CORE_LOCAL_H__ */

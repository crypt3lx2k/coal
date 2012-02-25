#ifndef COAL_CORE_LOCAL_H__
#define COAL_CORE_LOCAL_H__

#include <coal/coal.h>

/**
 * coal_core_collector
 * Calls del on the object pointed to.
 * Needed to implement the coal_local macro.
 *
 * @param (var *) pointer to object that is to be deleted
 */
cfundecl__ (void coal_core_collector (var * ptr));

/* tags a variable to be collected upon
   going out of scope */
/* in case it isn't obvious, don't use this */
#define coal_local __attribute__ ((cleanup(coal_core_collector)))

#endif /* COAL_CORE_LOCAL_H__ */

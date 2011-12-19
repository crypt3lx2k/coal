#ifndef __COAL_CORE_MEMORY_H
#define __COAL_CORE_MEMORY_H

#include <coal/core/namespace.h>

#ifndef __COAL_IMPLEMENTATION_H
# error "Never include <coal/core/memory.h> directly; use <coal/implementation.h> instead."
#endif

/**
 * core(malloc)
 * See malloc (3).
 * The purpose of this function
 * is to throw an exception in the event
 * that malloc (3) fails, currently it's
 * just an alias to malloc.
 *
 * @param  (size_t) number of bytes to allocate
 * @return (void *) pointer to allocated memory
 */
__cfundecl (void * core(malloc), (size_t size));

#ifdef CORE_NAMESPACE_POLLUTE
/* why do I have a bed feeling about this? */
# define malloc core(malloc)
#endif

#endif /* __COAL_CORE_MEMORY_H */

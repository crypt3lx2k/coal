#ifndef __COAL_CORE_MEMORY_H
#define __COAL_CORE_MEMORY_H

#ifndef __COAL_IMPLEMENTATION_H
# error "Never include <coal/core/memory.h> directly; use <coal/implementation.h> instead."
#endif

/**
 * lib(malloc)
 * See malloc (3).
 * The purpose of this function
 * is to throw an exception in the event
 * that malloc (3) fails, currently it's
 * just an alias to malloc.
 *
 * @param  (size_t) number of bytes to allocate
 * @return (void *) pointer to allocated memory
 */
__cfundecl (void * lib(malloc), (size_t size));

#endif /* __COAL_CORE_MEMORY_H */

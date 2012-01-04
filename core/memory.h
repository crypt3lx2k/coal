#ifndef COAL_CORE_MEMORY_H__
#define COAL_CORE_MEMORY_H__


#ifndef COAL_CORE_IMPLEMENTATION_H__
# error "Never include <coal/core/memory.h> directly; use <coal/core/implementation.h> instead."
#endif

/**
 * coal_core_malloc
 * See malloc (3).
 * The purpose of this function
 * is to throw an exception in the event
 * that malloc (3) fails, currently it's
 * just an alias to malloc.
 *
 * @param  (size_t) number of bytes to allocate
 * @return (void *) pointer to allocated memory
 */
cfundecl__ (void * coal_core_malloc (size_t size)) __attribute__ ((malloc));

#endif /* COAL_CORE_MEMORY_H__ */

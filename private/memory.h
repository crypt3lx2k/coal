#ifndef COAL_PRIVATE_MEMORY_H
#define COAL_PRIVATE_MEMORY_H

#include <coal/private/cdefs.h>

/**
 * coal_private_malloc
 * See malloc().
 * The purpose of this function is to throw an
 * exception in the event that malloc(3) fails.
 *
 * @param  (size_t) number of bytes to allocate
 * @return (void *) pointer to allocated memory
 */
coal_cfunspec void * coal_private_malloc (size_t size) coal_funattr_malloc;

/**
 * coal_private_realloc
 * See realloc().
 * See coal_private_malloc().
 *
 * @param  (void *) pointer to memory block
 * @param  (size_t) size in bytes of new block
 * @return (void *) reallocated block
 */
coal_cfunspec void * coal_private_realloc (void * ptr, size_t size);

#endif /* COAL_PRIVATE_MEMORY_H */

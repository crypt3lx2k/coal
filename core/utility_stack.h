#ifndef COAL_CORE_UTILITY_STACK_H__
#define COAL_CORE_UTILITY_STACK_H__

#include <stddef.h>
#include <stdlib.h>

#define UTILITY_STACK_RESIZE_FACTOR (0.70)

/**
 * utility_stack(type)
 * Generic stack, based
 * on a dynamic array.
 *
 * Provides O(1) push, peek,
 * pop, size, and is_empty
 * operations.
 *
 * @param (identifier) type contained
 */
#define utility_stack(type)                     \
  struct {                                      \
    type * base;                                \
    type * read;                                \
    type * end;                                 \
  }

/**
 * named_utility_stack
 * See utility_stack(type).
 *
 * The purpose of this macro is to define
 * a struct with a name, which is useful
 * in scenarios where you have to define
 * the same stack in several different
 * files.
 */
#define named_utility_stack(name, type)         \
  struct name {                                 \
    type * base;                                \
    type * read;                                \
    type * end;                                 \
  }

/**
 * utility_stack_zero
 * Provides a valid constant zero sized
 * utility_stack of any type.
 *
 * @return (utility_stack(type)) zero sized utility_stack
 */
#define utility_stack_zero() {NULL, NULL, NULL}

/**
 * utility_stack_init
 * Initializes stack to hold initially
 * size members.
 *
 * @param  (utility_stack(type) *) stack to initalize
 * @param  (size_t) initial size of stack
 * @return (utility_stack(type) *) initialized stack or NULL
 */
#define utility_stack_init(stack, size)                 \
  ({                                                    \
    typeof(stack) s__ = (stack);                        \
                                                        \
    s__->base = malloc(size * sizeof(*s__->base));      \
    s__->read = s__->base;                              \
    s__->end  = s__->base + size;                       \
                                                        \
    s__->base == NULL ? NULL : s__;                     \
  })

/**
 * utility_stack_clear
 * Empties stack and frees internal array.
 *
 * @param  (utility_stack(type) *) stack to clear
 * @return (utility_stack(type) *) cleared stack
 */
#define utility_stack_clear(stack)              \
  ({                                            \
    typeof(stack) s__ = (stack);                \
                                                \
    free(s__->base);                            \
    s__->base = NULL;                           \
    s__->read = s__->base;                      \
    s__->end  = s__->base + 0;                  \
    s__;                                        \
  })

/**
 * utility_stack_push
 * Pushes element onto stack.
 *
 * On error it will return NULL casted to type,
 * whether this makes sense depends on the type
 * used but for instance if the type is int then
 * it will just return the integer value of NULL,
 * which might even be the value you pushed.
 * I might change the error return to something
 * more sane in the future so don't rely on it.
 *
 * On error the stack is not invalidated but it
 * is also not modified.
 *
 * @param  (utility_stack(type) *) stack in question
 * @param  (type) element to push onto stack
 * @return (type) the element pushed or (type) NULL
 */
#define utility_stack_push(stack, element)              \
  ({                                                    \
    typeof(stack)     s__ = (stack);                    \
    typeof(element)   e__ = (element);                  \
    typeof(s__->base) b__ = s__->base;                  \
                                                        \
    if (s__->read == s__->end) {                        \
      ptrdiff_t read_offset__;                          \
      ptrdiff_t size__;                                 \
                                                        \
      read_offset__ = (s__->read - s__->base);          \
      size__ = (s__->end - s__->base);                  \
                                                        \
      b__ = realloc(s__->base,                          \
                    ((size_t)                           \
                     ((UTILITY_STACK_RESIZE_FACTOR +    \
                       1) *                             \
                      size__) + 1) *                    \
                    sizeof(*s__->base));                \
                                                        \
      if (b__ != NULL) {                                \
        s__->base = b__;                                \
        s__->read = s__->base + read_offset__;          \
        s__->end  = s__->base +                         \
          (size_t) ((UTILITY_STACK_RESIZE_FACTOR + 1) * \
                    size__) + 1;                        \
      }                                                 \
    }                                                   \
                                                        \
    b__ == NULL ?                                       \
      (typeof(*s__->base)) NULL :                       \
      (*s__->read++ = e__);                             \
  })

/**
 * utility_stack_pop
 * Removes and returns the
 * element at the top of
 * the stack.
 *
 * @param  (utility_stack(type) *) stack in question
 * @return (type) the element popped or (type) NULL
 */
#define utility_stack_pop(stack)                \
  ({                                            \
    typeof(stack) s__ = (stack);                \
                                                \
    s__->read == s__->base ?                    \
      (typeof(*s__->read)) NULL :               \
      *--s__->read;                             \
  })

/**
 * utility_stack_peek
 * Returns the element at
 * the top of the stack
 * without removing it.
 *
 * @param  (const utility_stack(type) *) stack in question
 * @return (type) element at the top of the stack or (type) NULL
 */
#define utility_stack_peek(stack)               \
  ({                                            \
    typeof(stack) s__ = (stack);                \
                                                \
    s__->read == s__->base ?                    \
      (typeof(*s__->read)) NULL :               \
      *(s__->read - 1);                         \
  })

/**
 * utility_stack_is_empty
 * Returns whether the stack is empty.
 *
 * @param  (const utility_stack(type) *) the stack in question
 * @return (type) true if the stack is empty false otherwise
 */
#define utility_stack_is_empty(stack)           \
  ({                                            \
    typeof(stack) s__ = (stack);                \
                                                \
    s__->base == s__->read;                     \
  })

/**
 * utility_stack_size
 * Returns the number of
 * elements on the stack.
 *
 * @param  (const utility_stack(type) *) the stack in question
 * @return (size_t) the number of elements on the stack
 */
#define utility_stack_size(stack)               \
  ({                                            \
    typeof(stack) s__ = (stack);                \
                                                \
    (size_t) (s__->read - s__->base);           \
  })

#endif /* COAL_CORE_UTILITY_STACK_H__ */
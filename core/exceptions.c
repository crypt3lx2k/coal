#include <coal/core/implementation.h>
#include <coal/core/exceptions.h>

thread_local struct exceptions_stack__ exceptions_s__ = utility_stack_zero();

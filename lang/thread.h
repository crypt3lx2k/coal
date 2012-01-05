#ifndef COAL_LANG_THREAD_H__
#define COAL_LANG_THREAD_H__

#include <coal/coal.h>

/**
 * coal_lang_thread
 * Class that represent a thread
 * of execution.
 *
 * @extends coal_lang_object
 * @constructor takes 2 arguments
 * @param (void *(*start_routine) (void *)) thread target
 * @param (void *) arguments to target
 */
cfundecl__ (const var coal_lang_thread (void));

/**
 * coal_lang_thread_join
 * Waits for thread to finish.
 *
 * @param (var) the thread in question
 */
cfundecl__ (void coal_lang_thread_join (var self));

/**
 * coal_lang_thread_start
 * Starts executing thread.
 *
 * @param (var) the thread in question
 */
cfundecl__ (void coal_lang_thread_start (var self));

#ifdef LANG_NAMESPACE_POLLUTE
# define thread       coal_lang_thread
# define thread_join  coal_lang_thread_join
# define thread_start coal_lang_thread_start
#endif

#ifdef THREAD_NAMESPACE_POLLUTE
# define join  coal_lang_thread_join
# define start coal_lang_thread_start
#endif

#endif /* COAL_LANG_THREAD_H__ */

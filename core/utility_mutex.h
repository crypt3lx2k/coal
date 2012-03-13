#ifndef COAL_CORE_UTILITY_MUTEX_H__
#define COAL_CORE_UTILITY_MUTEX_H__

/*
 * The following macros are only a thin layer over the
 * pthread_mutex functions. The reason these exist is to ease
 * any possible future transition away from the pthread
 * library to something else, or to add functionality later
 * like better error checking or deadlock detection.
 *
 * Will likely add functionality on an need to implement
 * basis.
 */

#include <pthread.h>

/**
 * utility_mutex
 * Mutual exclusion lock.
 */
typedef pthread_mutex_t utility_mutex;

/**
 * utility_mutex_open
 * Provides a valid constant open
 * utility_mutex.
 *
 * @return (utility_mutex) open utility_mutex
 */
#define utility_mutex_open() PTHREAD_MUTEX_INITIALIZER

/**
 * utility_mutex_lock
 * Attempts to acquire the mutex,
 * will block until the thread is
 * successful.
 *
 * @param  (utility_mutex *) the mutex in question
 * @return (int) zero on success and non-zero otherwise
 */
#define utility_mutex_lock(mutex) \
  pthread_mutex_lock(mutex)

/**
 * Attemps to acquire the mutex,
 * will not block if the thread
 * is unsuccessful in doing so.
 *
 * @param  (utility_mutex *) the mutex in question
 * @return (int) zero on success and non-zero otherwise
 */
#define utility_mutex_trylock(mutex) \
  pthread_mutex_trylock(mutex);

/**
 * utility_mutex_unlock
 * Attempts to unlock the mutex.
 *
 * @param  (utility_mutex *) the mutex in question
 * @return (int) zero on success and non-zero otherwise
 */
#define utility_mutex_unlock(mutex) \
  pthread_mutex_unlock(mutex)

#endif /* COAL_CORE_UTILITY_MUTEX_H__ */

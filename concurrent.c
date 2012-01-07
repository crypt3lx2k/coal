#include <pthread.h>

#include <coal/core/implementation.h>
#include <coal/concurrent.h>

void coal_concurrent_exit (void) {
  pthread_exit(NULL);
}

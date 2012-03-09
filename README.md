Have fun browsing the code, more to follow.

Here is the current class hierarchy, generated using hierarchy.py and the graphviz tool `dot'.

![Alt text](https://github.com/crypt3lx2k/coal/raw/master/classes.png)

Here is a small test program, test.c,
it is an implementation of the sleepsort algorithm.

```C
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <coal/lang/thread.h>

#include <coal/util/ArrayList.h>
#include <coal/util/collection.h>

void * target (void * args) {
  int number = atoi(args);

  sleep(number);
  printf("%d\n", number);
  fflush(stdout);

  return NULL;
}

int main (int argc, char * argv[]) {
  int i;
  var threads = new(ArrayList(), 0, 0.0);

  if (argc < 2) {
    fprintf(stderr,
	    "usage: %s number [number...]\n",
	    argv[0]);
    exit(EXIT_FAILURE);
  }

  for (i = 2; i < argc; i++)
    collection_add(threads, new(thread(), target, argv[i]));

  foreach (var t, threads) {
    thread_start(t);
  } foreach_end;

  target(argv[1]);

  /* del on collection implicitly
     deletes elements in collection */
  /* del on a thread implicitly
     joins with the thread */
  del(threads);

  return 0;
}
```

If you have installed the libcoal.so to your /usr/lib you may compile it with
    $ gcc -I ../ -DCOAL_NAMESPACE_POLLUTE -DLANG_NAMESPACE_POLLUTE -DUTIL_NAMESPACE_POLLUTE -DIO_NAMESPACE_POLLUTE -DCOAL_USER_EXCEPTIONS -DCOAL_USER_FOREACH -O0 -g -lcoal test.c

And run it with
    $ ./a.out

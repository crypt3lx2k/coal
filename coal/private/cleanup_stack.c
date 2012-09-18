#include <stdio.h> /* perror */
#include <stdlib.h>

#include <coal/private/pointer_stack.h>
#include <coal/private/thread_local.h>

#include <coal/private/cleanup_stack.h>

struct coal_private_cleanup_struct {
  coal_private_cleanup_fn routine;
  void * args;
};

static thread_local struct coal_private_pstack coal_private_cleanup_stack = COAL_PRIVATE_PSTACK_INITIALIZER;

void coal_private_cleanup_pop (int execute) {
  struct coal_private_cleanup_struct * h;

  h = coal_private_pstack_pop(&coal_private_cleanup_stack);

  if (execute && h != NULL) {
    h->routine(h->args);
  }

  free(h);
}

void coal_private_cleanup_push (coal_private_cleanup_fn routine, void * args) {
  struct coal_private_cleanup_struct * h;

  /* would love a better solution here, perhaps a better stack
     type with some evil preprocessor ugliness to make it
     `generic' */
  h = malloc(sizeof(*h));

  if (h == NULL) {
    perror("fatal stack error");
    abort();
  }

  h->routine = routine;
  h->args    = args;

  coal_private_pstack_push(&coal_private_cleanup_stack, h);
}

void coal_private_cleanup_run_all (void * ign coal_attr_unused) {
  while (!coal_private_pstack_isEmpty(&coal_private_cleanup_stack))
    coal_private_cleanup_pop(1);

  coal_private_pstack_destroy(&coal_private_cleanup_stack);
}

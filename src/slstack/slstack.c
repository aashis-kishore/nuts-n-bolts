#include "slstack.h"

#include <stdlib.h>

#include "sllist.h"

typedef struct _SLStack {
  SLList* list;
} SLStack;

SLStack* sls_new() {
  SLStack* stack = calloc(1, sizeof(SLStack));

  if (!stack) {
    perror("Failed to create stack\n");
    return stack;
  }

  stack->list = sll_new();

  if (!stack->list) {
    free(stack);
    stack = NULL;
    return stack;
  }

  return stack;
}

void sls_del(SLStack* stack) {
  if (stack) {
    if (stack->list) {
      sll_del(stack->list);
    }

    free(stack);
    stack = NULL;
  }
}

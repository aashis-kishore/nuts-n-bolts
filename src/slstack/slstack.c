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

bool sls_is_empty(SLStack* stack) {
  if (stack && stack->list) {
    return !sll_len(stack->list);
  }

  return false;
}

void sls_push(SLStack* stack, void* data) {
  if (stack) {
    sll_insert(stack->list, data, 0);
  }
}

void* sls_peek(SLStack* stack) {
  if (stack) {
    return sll_data(stack->list, 0);
  }

  return NULL;
}

void* sls_pop(SLStack* stack) {
  if (stack) {
    return sll_remove(stack->list, 0);
  }

  return NULL;
}

void sls_del(SLStack* stack) {
  if (stack) {
    sll_del(stack->list);

    free(stack);
    stack = NULL;
  }
}

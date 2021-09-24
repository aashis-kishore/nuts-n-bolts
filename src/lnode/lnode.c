#include <stdio.h>
#include <stdlib.h>
#include "lnode.h"

typedef struct _LNode {
  void* data;
  struct _LNode* next;
} LNode;

LNode* new_node(void* data) {
  LNode* node = calloc(1, sizeof(LNode));

  if (!node) {
    perror("Unable to allocate memory\n");
    return node;
  }

  node->data = data;
  node->next = NULL;

  return node;
}

void link_node(LNode* n1, LNode* n2) {
  if (n1 && n2) {
    n1->next = n2;
  }
}

LNode* next_node(LNode* node) {
  if (node) {
    return node->next;
  }

  return NULL;
}

void del_node(LNode* node) {
  if (node) {
    free(node);
    node = NULL;
  }
}

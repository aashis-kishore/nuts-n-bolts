#include "slnode.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _SLNode {
  void* data;
  struct _SLNode* next;
} SLNode;

SLNode* sln_new(void* data) {
  SLNode* node = calloc(1, sizeof(SLNode));

  if (!node) {
    perror("Unable to allocate memory\n");
    return node;
  }

  node->data = data;
  node->next = NULL;

  return node;
}

void sln_link(SLNode* n1, SLNode* n2) {
  if (n1 && n2) {
    n1->next = n2;
  }
}

SLNode* sln_next(SLNode* node) {
  if (node) {
    return node->next;
  }

  return NULL;
}

void sln_set_next(SLNode* node, SLNode* next) {
  if (node) {
    node->next = next;
  }
}

void* sln_data(SLNode* node) {
  if (node) {
    return node->data;
  }

  return NULL;
}

void sln_set_data(SLNode* node, void* data) {
  if (node) {
    node->data = data;
  }
}

void sln_del(SLNode* node) {
  if (node) {
    free(node);
    node = NULL;
  }
}

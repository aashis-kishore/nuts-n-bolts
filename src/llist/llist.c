#include <stdio.h>
#include <stdlib.h>
#include "lnode.h"
#include "llist.h"

typedef struct _LList {
  size_t length;
  LNode* begin;
  LNode* end;
} LList;

LList* new_list() {
  LList* llist = calloc(1, sizeof(LList));

  if (!llist) {
    perror("Unable to allocate memory\n");
    return llist;
  }

  llist->length = 0;
  llist->begin = NULL;
  llist->end = NULL;

  return llist;
}

void del_list(LList* list) {
  if (list) {
    if (list->begin && list->end) {
      LNode* node = NULL;

      while (node) {
        list->begin = next_node(node);
        del_node(node);
        node = list->begin;
      }

    }

    free(list);
    list = NULL;
  }
}

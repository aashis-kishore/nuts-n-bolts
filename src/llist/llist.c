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

void append_data(LList* list, void* data) {
  if (list) {
    LNode* node = new_node(data);

    if (!node) {
      perror("Unable to append data to list\n");
      return;
    }

    if (!(list->begin && list->end)) {
      list->begin = list->end = node;
      list->length++;
      return;
    }

    link_node(list->end, node);
    list->end = node;
    list->length++;
  }
}

void* ll_get_data(LList* list, size_t at) {
  if (list && at < list->length) {
    LNode* node = list->begin;

    size_t i = 0;
    while (node && i < at) {
      node = next_node(node);
      i++;
    }

    return get_data(node);
  }

  return NULL;
}

size_t len_list(LList* list) {
  return list ? list->length : 0;
}

void del_list(LList* list) {
  if (list) {
    if (list->begin && list->end) {
      LNode* node = list->begin;

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

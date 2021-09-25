#include "sllist.h"

#include <stdlib.h>

#include "slnode.h"

typedef struct _SLList {
  size_t length;
  SLNode* begin;
  SLNode* end;
} SLList;

SLList* sll_new() {
  SLList* list = calloc(1, sizeof(SLList));

  if (!list) {
    perror("Unable to allocate memory\n");
    return list;
  }

  list->length = 0;
  list->begin = NULL;
  list->end = NULL;

  return list;
}

void sll_append(SLList* list, void* data) {
  if (list) {
    SLNode* node = sln_new(data);

    if (!node) {
      perror("Unable to append data to list\n");
      return;
    }

    if (!(list->begin && list->end)) {
      list->begin = list->end = node;
      list->length++;
      return;
    }

    sln_link(list->end, node);
    list->end = node;
    list->length++;
  }
}

void* sll_data(SLList* list, size_t at) {
  if (list && at < list->length) {
    SLNode* node = list->begin;

    size_t i = 0;
    while (node && i < at) {
      node = sln_next(node);
      i++;
    }

    return sln_data(node);
  }

  return NULL;
}

size_t sll_len(SLList* list) { return list ? list->length : 0; }

void sll_del(SLList* list) {
  if (list) {
    if (list->begin && list->end) {
      SLNode* node = list->begin;

      while (node) {
        list->begin = sln_next(node);
        sln_del(node);
        node = list->begin;
      }
    }

    free(list);
    list = NULL;
  }
}

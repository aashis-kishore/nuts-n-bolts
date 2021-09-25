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

void sll_insert(SLList* list, void* data, size_t at) {
  if (list && at >= 0 && at <= list->length) {
    SLNode* new_node = sln_new(data);

    if (!new_node) {
      perror("Unable to insert data into list\n");
      return;
    }

    SLNode* prev = NULL;
    SLNode* node = list->begin;

    size_t i = 0;
    while(node && i < at) {
      prev = node;
      node = sln_next(node);
      i++;
    }

    if (prev && node) {
      sln_link(prev, new_node);
      sln_link(new_node, node);
    } else if (!prev) {
      sln_link(new_node, list->begin);
      list->begin = new_node;
    } else if (!sln_next(node)) {
      sln_link(list->end, new_node);
      list->end = new_node;
    }

    list->length++;
  }
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

void* sll_remove(SLList* list, size_t at) {
  void* data = NULL;

  if (list && at < list->length) {
    SLNode* prev = NULL;
    SLNode* node = list->begin;

    size_t i = 0;
    while(node && i < at) {
      prev = node;
      node = sln_next(node);
      i++;
    }

    if (prev && node) {
      sln_link(prev, sln_next(node));
    } else if (!prev) {
      list->begin = sln_next(list->begin);
    } else if (!sln_next(node)) {
      list->end = prev;
      sln_set_next(list->end, NULL);
    }

    data = sln_data(node);
    sln_del(node);
    list->length--;

    if (list->length == 0) {
      list->begin = list->end = NULL;
    }
  }

  return data;
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

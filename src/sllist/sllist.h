#ifndef _SLLIST_H_
#define _SLLIST_H_

#include <stdio.h>

typedef struct _SLList SLList;

SLList* sll_new();
void sll_insert(SLList* list, void* data, size_t at);
void sll_append(SLList* list, void* data);
void* sll_remove(SLList* list, size_t at);
void* sll_data(SLList* list, size_t at);
size_t sll_len(SLList* list);
void sll_del(SLList* list);

#endif

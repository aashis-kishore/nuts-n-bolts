#ifndef _SLLIST_H_
#define _SLLIST_H_

#include <stdio.h>

typedef struct _SLList SLList;

SLList* sll_new_list();
void sll_append_data(SLList* list, void* data);
void* sll_get_data(SLList* list, size_t at);
size_t sll_len_list(SLList* list);
void sll_del_list(SLList* list);

#endif

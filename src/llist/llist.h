#ifndef _LLIST_H_
#define _LLIST_H_

typedef struct _LList LList;

LList* new_list();
void append_data(LList* list, void* data);
size_t len_list(LList* list);
void del_list(LList* list);

#endif

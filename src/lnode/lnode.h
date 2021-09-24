#ifndef _LNODE_H_
#define _LNODE_H_

typedef struct _LNode LNode;

LNode* new_node(void* data);
void link_node(LNode* n1, LNode* n2);
LNode* next_node(LNode* node);
void* get_data(LNode* node);
void del_node(LNode* node);

#endif



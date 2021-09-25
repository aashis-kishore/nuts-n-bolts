#ifndef _SLNODE_H_
#define _SLNODE_H_

typedef struct _SLNode SLNode;

SLNode* sln_new_node(void* data);
void sln_link_node(SLNode* n1, SLNode* n2);
SLNode* sln_next_node(SLNode* node);
void* sln_get_data(SLNode* node);
void sln_del_node(SLNode* node);

#endif



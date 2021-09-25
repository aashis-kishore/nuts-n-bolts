#ifndef _SLNODE_H_
#define _SLNODE_H_

typedef struct _SLNode SLNode;

SLNode* sln_new(void* data);
void sln_link(SLNode* n1, SLNode* n2);
SLNode* sln_next(SLNode* node);
void* sln_data(SLNode* node);
void sln_del(SLNode* node);

#endif

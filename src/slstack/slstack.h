#ifndef _SLSTACK_H_
#define _SLSTACK_H_

#include <stdbool.h>

typedef struct _SLStack SLStack;

SLStack* sls_new();
bool sls_is_empty(SLStack* stack);
void sls_push(SLStack* stack, void* data);
void* sls_peek(SLStack* stack);
void* sls_pop(SLStack* stack);
void sls_del(SLStack* stack);

#endif

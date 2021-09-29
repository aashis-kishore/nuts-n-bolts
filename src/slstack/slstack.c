#include "slstack.h"

#include "sllist.h"

typedef struct _SLStack {
  SLList* list;
} SLStack;

SLStack* sls_new() { return NULL; }

void sls_del(SLStack* stack) {
  if (stack) {
  }
}

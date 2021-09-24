#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  int data;
  struct _Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void append(int data) {
  Node* node = calloc(1, sizeof(Node));

  if (!node) {
    perror("Failed to allocate memory\n");
    exit(2);
  }

  node->data = data;
  node->next = NULL;

  if (!head) {
    head = node;
    tail = node;
    return;
  }

  tail->next = node;
  tail = node;
}

void append_many(int* data, size_t count) {
  for (size_t i = 0; i < count; i++) {
    append(data[i]);
  }
}

void print() {
  Node* node = head;

  while(node) {
    printf("%d ", node->data);
    node = node->next;
  }

  printf("\n");
}

void clear_list() {
  Node* node = NULL;

  while(head) {
    node = head;
    head = head->next;

    free(node);
  }
}

void list() {
  int data[] = {1, 2, 3, 4, 5};

  append_many(data, sizeof(data) / sizeof(data[0]));
  print();

  clear_list();
}

int main(void) {
  list();

  return EXIT_SUCCESS;
}

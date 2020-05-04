#include <stdio.h>

struct list_node {
  unsigned char data;
  struct list_node *next;
  struct list_node *previous;
};

struct linked_list {
  struct list_node *head;
};

void append(struct linked_list *list, struct list_node *node) {
  if (list == NULL) {
    struct linked_list emtpy_list = {};
    list = &emtpy_list;
  }

  if (list->head == NULL) {
    list->head = node;
    return;
  }

  struct list_node *current = list->head;

  while (current->next != NULL) {
    // Change to the next node in the list
    current = current->next;
  }

  node->previous = current;
  current->next = node;
  return;
}

int list_length(struct linked_list* list) {
  if (list->head == NULL) {
    return 0;
  }

  struct list_node *current = list->head;
  int length = 1;

  while (current->next != NULL) {
    current = current->next;
    length++;
  }
  
  return length;
}

void move_head_next(struct linked_list* list) {
  if (list->head->next == NULL) {
    return;
  }

  list->head = list->head->next;
}

void move_head_previous(struct linked_list* list) {
  if (list->head->previous == NULL) {
    return;
  }

  list->head = list->head->previous;
}

int main() {
  struct linked_list list = {};


  struct list_node a = {(char)23, NULL};
  struct list_node b = {(char)45, NULL};
  struct list_node c = {(char)86, NULL};
  struct list_node d = {(char)90, NULL};

  append(&list, &a);
  append(&list, &b);
  append(&list, &c);
  append(&list, &d);

  printf("%d\n", list.head->data);
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  struct node *next;
  struct node *prev;
} node;

typedef struct list_t {
  node* head;
  node* tail;
  int length;
} list_t;

void inserAt(list_t* list, int idx, int data);
void append(list_t* list, int data);
void removeHead(list_t* list);
void prepend(list_t* list, int data);
void removeAt(list_t* list, int idx);
void print_list_forward(list_t* list);

int main(void) {

  list_t* list = NULL;
  list = (struct list_t*)malloc(sizeof(list_t)); 

  append(list, 30);
  append(list, 3);
  append(list, 100);
  removeHead(list);
  prepend(list, 69);
  prepend(list, 96);
  inserAt(list, 3, 85);
  removeAt(list, 1);

  print_list_forward(list);
  printf("%d\n", list->length);

  return 0;
}

void inserAt(list_t* list, int idx, int data){
  if (idx > list->length) {
    printf("too much list");
    exit(1);
  } else if (idx == list->length) {
    append(list, data);
    return;
  } else if (idx == 0) {
    prepend(list, data);
    return;
  }

  node *curr = list->head;
  for (int i = 0; i < idx; i++) {
    curr = curr->next; 
  }

  node *new_node = (node *)malloc(sizeof(node));
  if (new_node == NULL) {
    printf("cannot allocate memory!");
    exit(1);
  }
  
  new_node->data = data;
  new_node->next = curr;
  new_node->prev = curr->prev;
  curr->prev->next = new_node;
  curr->prev = new_node;

  list->length += 1;
}

void removeAt(list_t *list, int idx) {
  if (idx >= list->length) {
    printf("too much list");
    exit(1);
  }

  if (idx == 0) {
    removeHead(list);
    return;
  }

  node *curr = list->head;
  for (int i = 0; i < idx; i++) {
    curr = curr->next; 
  }
  if (curr->next == NULL) {
    curr->next->prev = NULL;
  } else {
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  list->length -= 1;
}
void append(list_t* list, int data) {
  if (list == NULL) {
    printf("cannot allocate memory!");
    exit(1);
  }

  node* new_node = (node *)malloc(sizeof(node)); 
  if (new_node == NULL) {
    printf("cannot allocate memory!");
    exit(1);
  }

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
  }
  else {
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->length += 1;
} 

void removeHead(list_t* list) {
  if (list == NULL) {
    printf("cannot allocate memory!");
    exit(1);
  }

  node *temp = list->head;
  list->head = list->head->next;

  if(list->head == NULL){
    list->tail = NULL;
    printf("List dont exist!");
    exit(1);
  } else {
    list->head->prev = NULL;
    list->length -= 1;
  }

  free(temp);
} 

void prepend(list_t* list, int data) {
  if (list == NULL) { 
    printf("cannot allocate memory!");
    exit(1);
  }

  node* new_node = (node *)malloc(sizeof(node)); 
  if (new_node == NULL) {
    printf("cannot allocate memory!");
    exit(1);
  }

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
  }
  else {
    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;
    list->head->prev = new_node;
    list->head = new_node;
  }
  list->length += 1;
} 

void print_list_forward(list_t* list) {
    if (list == NULL || list->head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    node* current = list->head;
    printf("List (forward): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

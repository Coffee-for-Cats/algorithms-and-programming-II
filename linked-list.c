#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int num;
  struct node *next;
} Node;

typedef struct list {
  Node *first;
} List;

void addLast(List *list, int number) {
  Node *new;
  new = (Node*) malloc(sizeof(Node));
  if(!new) printf("Erro de alocacao.");
  else {
    new->num = number;
    new->next = NULL;

    if(list->first == NULL) {
      list->first = new;
    } else {
      Node *actual = list->first;
      while(actual->next != NULL) {
        actual = actual->next;
      }
      actual->next = new;
    }
  }
}

void addFirst(List *list, int number) {
  Node *new;
  new = (Node*) malloc(sizeof(Node));
  if(!new) printf("Erro de alocacao.");
  else {
    new->num = number;
    Node* temp;
    temp = list->first;
    list->first = new;
    new->next = temp;
  }
}

void view(List *list) {
  Node *actual = list->first;
  while(actual != NULL) {
    printf("%d ", actual->num);
    actual = actual->next;
  }
}

void recDel(Node *node) {
  if(node->next) recDel(node->next);
  free(node);
}

void delete(List *list) {
  recDel(list->first);
  list->first = NULL;
}

// nextTo is the number that will be previous to the numberAdded.
void addMid(List *list, int nextTo, int addNumber) {
  Node* new = (Node*) malloc(sizeof(Node));
  if(!new) printf("Erro de alocacao.");
  else {
    Node* actual = list->first;
    while(actual && actual->num != nextTo) {
      actual = actual->next;
    }
    if(!actual) printf("Valor nao encontrado.");
    else {
      new->num = addNumber;
      if(actual->next == NULL)
        new->next = NULL;
      else {
        new->next = actual->next;
        actual->next = new;
      }
    }
  }
}

int main() {
  List list;
  list.first = NULL;

  addLast(&list, 4);
  addLast(&list, 6);
  addFirst(&list, 3);
  addMid(&list, 4, 12);

  view(&list);
  delete(&list);
}
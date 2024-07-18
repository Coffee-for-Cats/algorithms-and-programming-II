#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int num;
  struct node* prox;
} Node;

Node* novo_no(int num) {
  Node* no = malloc(sizeof(Node));
  no->prox = NULL;
  no->num = num;
  return no;
}

void adiciona_inicio(Node** lista, int num) {
  Node* novo = novo_no(num);

  if(*lista != NULL) novo->prox = *lista;
  *lista = novo;
}

void printa_lista(Node** lista) {
  Node* no = *lista;
  while(no != NULL) {
    printf("%d ", no->num);
    no = no->prox;
  }
}

void printa_lista2(Node* lista) {
  printf("%d ", lista->num);
  if(lista->prox) printa_lista2(lista->prox); 
}

int main() {
  // lista com 0 itens
  Node* lista = NULL;
  adiciona_inicio(&lista, 5);
  adiciona_inicio(&lista, 10);
  adiciona_inicio(&lista, 3);
  printa_lista2(lista);
}
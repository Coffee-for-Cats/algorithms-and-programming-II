#include <stdio.h>
#include <stdlib.h>

typedef struct inspecao {
  int hora;
  int producao;
  struct inspecao *prox;
} Inspecao;

int getHora() {
  int hora;
  do {
    printf("Digite a hora da inspecao: ");
    scanf("%d", &hora);
  } while(hora > 24 || hora < 0);
  return hora;
}

int getProd() {
  int producao;
  do {
    printf("Quantos produtos foram produzidos? ");
    scanf("%d", &producao);
  } while(producao < 1);
  return producao;
}

Inspecao* addLista(Inspecao* lista, Inspecao* item) {
  Inspecao* returning;

  if(lista == NULL) {
    returning = item;
  } else {
    returning = lista;
    Inspecao *atual = lista;
    while(atual->prox != NULL) {
      atual = atual->prox;
    }
    atual->prox = item;
  }

  return returning;
} 

void printLista(Inspecao* lista) {
  if(lista == NULL) return;
  printf("Hora: %d | Prod: %d\n", lista->hora, lista->producao);
  if(lista->prox) printLista(lista->prox);
}

void printMaisCedo(Inspecao* lista) {
  Inspecao *menorHora = lista;

  Inspecao* atual = lista;  
  while(atual->prox != NULL) {
    if(atual->hora < menorHora->hora) {
      menorHora = atual;
    }
    atual = atual->prox;
  }
  printf("O mais cedo foi:\nHora: %d | Prod: %d\n", lista->hora, lista->producao);
}

int main() {
  int hora, producao;

  Inspecao* novaInspecao;
  Inspecao* lista = NULL;

  int count = 1;

  do {
    printLista(lista);
    novaInspecao = malloc(sizeof(Inspecao));
    printf("\nInspecao n%d\n", count++);
    novaInspecao->hora = getHora();
    novaInspecao->producao = getProd();
    novaInspecao->prox = NULL;
    lista = addLista(lista, novaInspecao);
  } while (novaInspecao->hora != 24);

  printMaisCedo(lista);
}
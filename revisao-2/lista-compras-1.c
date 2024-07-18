/*
Desenvolva um programa que controle as compras do supermercado. Para isso deve-se inserir os itens da lista de compras em um arquivo. Você irá armazenar o produto (pode ser código ou nome) e a quantidade a ser comprada. Durante a compra o arquivo deve ser atualizado com a informação sobre o preço do item e se ele estava disponível ou não no mercado. Você deve implementar um menu:
1- Insere item na lista de compras 
2- Insere situação (disponível ou em falta)
3- Valor do item 
4- Imprime a lista de compras
5- Fim
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum situacao { disponivel, indisponivel, nao_sei } Situacao;

typedef struct compra {
  char produto[20];
  int quantidade;
  Situacao situacao;
  float valor;
} Compra;

typedef struct node {
  Compra* compra;
  struct node* prox;
} Node;

void atualiza_arquivo(Node** lista) {
  FILE* file = fopen("lista-compras.txt", "rw+");

  Node* atual = *lista;
  while(atual != NULL) {
    fprintf(file, "%s;", atual->compra->produto);
    fprintf(file, "%d;", atual->compra->quantidade);
    fprintf(file, "%d;", atual->compra->situacao);
    fprintf(file, "%.2f;", atual->compra->valor);
    fprintf(file, "\n");
    atual = atual->prox;
  }
}

void add_item(Node** lista) {
  Compra* novo_item = malloc(sizeof(novo_item));
  if(!novo_item) printf("Problema de alocacao.");
  fflush(stdin);
  puts("\nQual o nome do produto a ser adicionado? ");
  fgets(novo_item->produto, 20, stdin);

  if(novo_item->produto[strlen(novo_item->produto) - 1] == '\n') 
    novo_item->produto[strlen(novo_item->produto) - 1] = '\0';

  fflush(stdin);
  puts("\nQuantos voce precisa comprar?");
  scanf("%d", &novo_item->quantidade);
  novo_item->situacao = nao_sei;
  novo_item->valor = -1; // equivalente a nao_sei, para valores

  Compra prod = *novo_item;
  printf("%s ", prod.produto);
  printf("%d ", prod.quantidade);
  printf("%d ", prod.situacao);
  printf("%.2f ", prod.valor);

  FILE* file = fopen("lista-compras.txt", "w+");
  if(file == NULL) printf("Problemas ao achar o arquivo");
  //fputs(novo_item->produto, file);
  fprintf(file, "%s", prod.produto);
  return;
  fprintf(file, "%d", prod.quantidade);
  fprintf(file, "%d", prod.situacao);
  fprintf(file, "%.2f", prod.valor);

  Node *novo_no = malloc(sizeof(Node));
  novo_no->prox = NULL;
  novo_no->compra = novo_item;

  if(*lista == NULL) *lista = novo_no;
  else {
    Node* atual = *lista;
    while(atual->prox != NULL) atual = atual->prox;
    atual->prox = novo_no;
  }
}

void mod_situacao(Node** lista) {
  char nome[20];
  puts("\nQual o nome do item que deseja modificar? ");
  fgets(nome, 20, stdin);
  int situacao;
  puts("\nQual a situacao? 1= disponivel, 2= indisponivel");
  scanf("%d", &situacao);

  Node* atual = *lista;
  while(
    strcmp(atual->compra->produto, nome) == 0
    && atual->prox != NULL
  ) atual = atual->prox;

  // estamos no item certo
  if(situacao == 1)
    atual->compra->situacao = disponivel;
  else
    atual->compra->situacao = indisponivel;

  atualiza_arquivo(lista);
}

void add_valor() {
  
}

void imprime_lista() {
  
}

int main() {
  int op;
  Node* lista = NULL;
  do {
    printf("1- Inserir itens");
    printf("\n2- Insere situacao");
    printf("\n3- Insere valor do item");
    printf("\n4- Imprime lista");
    printf("\n5- Fim/Sair\n");
    scanf("%d", &op);
    switch (op) {
      case 1: add_item(&lista); break;
      case 2: mod_situacao(&lista); break;
      case 3: add_valor(&lista); break;
      case 4: imprime_lista(&lista); break;
      case 5: printf("\nSaindo..."); break;
      default: printf("Erro!");
    }
  } while (op != 5);
}
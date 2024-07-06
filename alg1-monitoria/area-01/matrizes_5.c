//5)	Faça um programa que crie duas matrizes 4 x 4 de inteiros  e posteriormente cria  uma terceira com os maiores valores de cada posição das matrizes lidas.

#include <stdio.h>

#define tam 4

int main() {
  int matriz1[tam][tam];
  for(int i = 0; i < tam; i++) {
    for(int j = 0; j < tam; j++) {
      printf("\nDigite o numero %d|%d da matriz 1: ", i, j);
      scanf("%d", &matriz1[i][j]);
    }
  }

  int matriz2[tam][tam];
  for(int i = 0; i < tam; i++) {
    for(int j = 0; j < tam; j++) {
      printf("\nDigite o numero %d|%d da matriz 2: ", i, j);
      scanf("%d", &matriz2[i][j]);
    }
  }

  // constroi a matriz3 com os maiores valores das anteriores
  int matriz3[tam][tam];
  for(int i = 0; i < tam; i++) {
    for(int j = 0; j < tam; j++) {
      if(matriz1[i][j] > matriz2[i][j])
        matriz3[i][j] = matriz1[i][j];
      else
        matriz3[i][j] = matriz2[i][j];
    }
  }

  //printa as 3 matrizes
  printf("Matriz 1 | Matriz 2\n");
  for(int i = 0; i < tam; i++) {
    for(int j = 0; j < tam; j++) {
      printf("%d ", matriz1[i][j]);
    }
    printf(" | ");
    for(int j = 0; j < tam; j++) {
      printf("%d ", matriz2[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz 3 (maiores valores entre as duas):\n");
  for(int i = 0; i < tam; i++) {
    for(int j = 0; j < tam; j++) {
      printf("%d ", matriz3[i][j]);
    }
    printf("\n");
  }
}
// 4)	Faça um programa que manipule com uma matriz 5 x 5 de inteiros. Leia também um valor inteiro independente. O programa deverá fazer uma busca à desse valor na matriz e, ao final, escrever a localização (linha e coluna) ou uma mensagem de “não encontrado”. 

#include <stdio.h>

#define tam 5

int main() {
  int matriz[tam][tam];
  for(int i = 0; i < tam; i++) {
    for(int j = 0; j < tam; j++) {
      printf("\nDigite um numero inteiro: ");
      scanf("%d", &matriz[i][j]);
    }
  }

  int independente;
  printf("\nDigite o valor independente: ");
  scanf("%d", &independente);

  int existe = 0;
  for(int i = 0; i < tam; i++) {
    for(int j = 0; j < tam; j++) {
      if(independente == matriz[i][j]) {
        existe = 1;
        printf("\nValor Encontrado!");
        printf("\nLinha: %d", i);
        printf("\nColuna: %d", j);
      }
    }
  }

  if(!existe) {
    printf("\nValor nao foi encontrado na matriz");
  }
}
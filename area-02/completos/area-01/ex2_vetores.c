//Elabore um programa que armazene valores em um vetor de inteiros com 10 posições e inicie cada elemento com o valor de 1 a 10. Codifique uma função recursiva  que imprima todos os elementos em ordem e uma função recursiva que imprima todos os elementos na ordem inversa.

#include <stdio.h>

void crescente(int *vet, int atual, int limite) {
  if (atual == limite) {
    return;
  } else {
    printf("%d ", vet[atual]);
    crescente(vet, ++atual, limite);
  }
}

void printaCrescente(int *vet, int tamanho) {
  crescente(vet, 0, tamanho);
}

int main() {
  int vet[] = {0,1,2,3,4,5,6,7,8,9};
  printaCrescente(vet, 10);
}
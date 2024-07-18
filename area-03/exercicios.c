/*
1- Faça um programa simples que printe uma escadinha; a altura da escada deve ser uma variavel.
Ex.:
  Escadinha => 4
  X
  X X
  X X X
  X X X X
*/

#include <stdio.h>

int main() {
  int n = 5;
  int h = n/2;

  // metade de cima
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < h - i; j++) {
      printf("  ");
    }
    for(int j = 0; j < i*2+1; j++) {
      printf("X ");
    }
    printf("\n");
  }
  //metade de baixo
  for(int i = h; i >= 0; i--) {
    for(int j = 0; j < h - i; j++) {
      printf("  ");
    }
    for(int j = 0; j < i*2+1; j++) {
      printf("X ");
    }
    printf("\n");
  }
}
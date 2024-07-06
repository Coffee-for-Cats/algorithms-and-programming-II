#include <stdio.h>

int fib(int geracoes) {
  if(geracoes <= 2) return 1;
  return fib(geracoes - 2) + fib(geracoes - 1);
}

int main() {
  int geracoes;
  do {
    printf("Digite o numero de geracoes: ");
    scanf("%d", &geracoes);
  } while(geracoes < 0);

  printf("A quantidade de coelhos eh: %d", fib(geracoes));
}
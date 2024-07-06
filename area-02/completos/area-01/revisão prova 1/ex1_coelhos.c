#include <stdio.h>

int geracao(int geracoes, int *numCoelhos) {
  if ()
  *numCoelhos += geracoes - 1;
  geracao(geracoes - 1, numCoelhos);
}
//todo
int main() {
  printf("Numero de geracoes: ");
  int geracoes;
  scanf("%d", &geracoes);

  int numCoelhos = 0;
  geracao(geracoes, &numCoelhos);
  printf("%d", numCoelhos);
}
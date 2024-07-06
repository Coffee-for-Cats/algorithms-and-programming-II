#include <stdio.h>

int main() {
  float *num1;
  int resto;

  // pega o input do usuário
  printf("Digite o 1 numero: ");
  scanf("%f", &num1);

  // a função "sum" consegue alterar o valor
  resto = division(&num1);

  printf("num1: %.2f", num1);
  printf("\n");
  printf("resto: %d", resto);
}

int division(float *num) {
  // faz o resto de uma vez
  int resto = (int) *num % 10;
  // modifica o "num1" lá da main.
  // precisa ser feito dps do calculo do resto.
  *num = *num / 10;
  // retorna o resto
  return resto;
}
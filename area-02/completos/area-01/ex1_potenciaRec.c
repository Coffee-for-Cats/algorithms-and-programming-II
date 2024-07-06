#include <stdio.h>
#include <stdlib.h>

int rec(int x, int y) {
  if(y == 0)  return 1;
  else        return x * rec(x, y - 1);
}

int main() {
  printf("Digite o numero 1: ");
  int num1;
  scanf("%d", &num1);

  int num2 = -1;
  do {
    printf("\nDigite o numero 2 (positivo): ");
    scanf("%d", &num2);
  } while (num2 < 0);
  
  printf("%d", rec(num1, num2));
}
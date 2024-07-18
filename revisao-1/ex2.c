#include <stdio.h>

int mult(int num1, int num2) {
  if(num2 == 0) return 0;
  return num1 + mult(num2, num2 -1 );
}

int main() {
  printf("%d", mult(4, 6));
}
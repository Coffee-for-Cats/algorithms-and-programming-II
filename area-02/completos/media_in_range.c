#include <stdio.h>

int soma_in_range(int num) {
  if (num > 0)
    return num + soma_in_range(num - 1);
  else
    return 0;
}

float media(int num) {
  return (float)soma_in_range(num) / num;
}

int main() {
  int num;
  scanf("%d", &num);
  printf("Media: %.2f", media(num));
}
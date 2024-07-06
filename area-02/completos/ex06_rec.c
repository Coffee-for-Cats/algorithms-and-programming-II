#include <stdio.h>
#include <math.h>

float serie(float x) {
  if (x == 1) return 1;
  return ((1 + pow(x, 2)) / x) + serie(x - 1);
}

int main() {
  printf("%.8f ", serie(4));
}
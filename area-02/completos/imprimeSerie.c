#include <stdio.h>

void imprimeSerie(int min, int max, int inc) {
  if(min > max) return;

  printf("%d ", min + inc);

  imprimeSerie(++min, max, inc);
}

int main() {
  imprimeSerie(5, 10, 3);
}
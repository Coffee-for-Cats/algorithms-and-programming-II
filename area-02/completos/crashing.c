#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  int *i, a;
  a = 54;
  i = &a;
  i++;
  printf("%d", *(i + 5000000));
}
#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
  //inverte caso necessário
  if(b > a) mdc(b, a);

  
}

int main() {
  printf("%d\n", mdc(25, 10));
}
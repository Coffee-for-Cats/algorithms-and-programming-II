#include <stdio.h>

int main() {
  FILE *file = fopen("dados.bin", "wb");

  for(int i = 0; i <= 100; i++) {
    fprintf(file, "%d\n", i);
  }

  fclose(file);
}
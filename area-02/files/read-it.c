#include <stdio.h>

int main() {
  FILE *file = fopen("dados.bin", "rb");

  int count = 1;
  while(!feof(file)) {
    char temp[60] = ""; int i = 0;
    
    char charac = ' ';
    while(charac != '\n') {
      temp[i++] = charac;
      charac = fgetc(file);
    }

    printf("%d > %s\n", count++, temp);
  }

  fclose(file);
}
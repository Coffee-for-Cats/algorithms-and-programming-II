#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *arquivo = fopen("test.txt", "r");
  if(arquivo == NULL)
    printf("Erro ao abrir arquivo");

  char charac[60];
  int result = 7;
  for (int i = 1; result != EOF; i++) {
    result = fscanf(arquivo, "%s", charac);
    printf("-> %s\n", charac);
  }
}
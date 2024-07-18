#include <stdio.h>
#include <stdlib.h>

int main() {
  char nome_arq[60];
  puts("Nome do arquivo: ");
  gets(nome_arq);
  FILE *arquivo = fopen(nome_arq, "r");

  int result = 1, line;
  char buffer[40];

  result = fscanf(arquivo, "%s", buffer);
  while (result != EOF) {
    printf("%d> %s\n", line++, buffer);
    result = fscanf(arquivo, "%s", buffer);
  }
}
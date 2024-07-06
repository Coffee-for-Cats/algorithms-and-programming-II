#include <stdio.h>

int main() {

  int usuario, idade, total_idade = 0, menor_idade = 0, total_usuarios = 0;

  printf("Idade: ");
  scanf("%d", &idade);

  if (idade == 0) {
    printf("Programa encerrado, nao ha registro.");
  } else {

    while (idade != 0) {

      printf("\nUsuario da plataforma (1-sim 2-nao): ");
      scanf("%d", &usuario);

      while (usuario != 1 && usuario != 2) {
        printf("\nERRO! valor inválido. 1-sim 2-nao ");
        scanf("%d", &usuario);
      }

      if (usuario == 1) {
        total_usuarios++;
        total_idade = total_idade + idade;
      }

      if (usuario == 2 && menor_idade == 0) {
        menor_idade = idade;
      } else if (idade < menor_idade && usuario == 2) {
        menor_idade = idade;
      }

      printf("Idade: ");
      scanf("%d", &idade);

      while (idade < 0) {
        printf("\nERRO! Idade nao pode ser negativa. Idade: ");
        scanf("%d", &idade);
      }
    }

    printf("\n\nA media das idades dos usuarios eh: %d.\nA menor idade entre os que nao sao usuarios eh: %d.",total_idade / total_usuarios, menor_idade);
  }

  return 0;
}

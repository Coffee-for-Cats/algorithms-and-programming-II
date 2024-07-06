//Implemente um programa que receba um nome completo (nome e sobrenome) e imprima 
//somente o sobrenome e a quantidade de letras que possui o sobrenome informado.

#include <stdio.h>
#include <string.h>

void nome(char *nome) {
  // acha o começo do sobrenome
  while(*nome != ' ' && nome[1] != '\0') { 
    if (nome[1] == '\0') printf("\nSobrenome nao encontrado!");
    nome++;
  }

  printf("\n");

  nome++;
  int count = 0;
  while(*nome != '\0') {
    printf("%c", *nome);
    nome++;
    count++;
  }
  printf("\no sobrenome tem %d caracteres.", count);
}

int main() {
  char nomeCompl[40];

  printf("Digite o seu nome completo: ");
  gets(nomeCompl);

  nome(nomeCompl);
}
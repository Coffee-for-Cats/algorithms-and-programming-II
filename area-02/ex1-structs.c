// 1)Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até 10 pessoas. 
// Cada pessoa deve ser representada por uma struct dentro de um vetor. 
// O nome, a data de nascimento e a altura de cada pessoa devem ser informados pelo teclado.
// Posteriormente imprima os nomes das pessoas que possuem altura superior a 1,78.

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  char nome[20];
  float altura;
  Data nascimento;
} Pessoa;

void perguntaNome(Pessoa *pessoa) {
  printf("\nDigite o nome: ");
  fflush(stdin);
  fgets(pessoa->nome, 20, stdin);
}

void perguntaAltura(Pessoa *pessoa) {
  printf("\nDigite sua altura: ");
  scanf("%f", &(pessoa->altura));
}

void perguntaNascimento(Pessoa *pessoa) {
  printf("\nDigite o nascimento: (dia - mes - ano) ");
  scanf(
    "%d %d %d",
    &(pessoa->nascimento.dia),
    &(pessoa->nascimento.mes),
    &(pessoa->nascimento.ano)
  );
}

#define size 2

int main() {
  Pessoa pessoas[size];

  for(int i = 0; i < size; i++) {
    printf("\nPessoa numero %d", i + 1);
    perguntaNome(&pessoas[i]);
    perguntaAltura(&pessoas[i]);
    perguntaNascimento(&pessoas[i]);
  }

  printf("\n\n PESSOAS MAIORES QUE 1.78: ");
  for(int i = 0; i < size; i++) {
    if(pessoas[i].altura >= 1.78) {
      printf("\nNome: %s", pessoas[i].nome);
    }
  }
}
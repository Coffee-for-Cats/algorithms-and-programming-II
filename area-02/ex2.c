// 2) Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova. 
// (a) Permita ao usuário entrar com os dados de 5 alunos. 
//  (b) Encontre o aluno com maior nota da primeira prova. 
// (c) Encontre o aluno com maior média geral. 
//  (d) Encontre o aluno com menor média geral 
//  (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação.

#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
  int matricula;
  char nome[30];
  int nota1;
  int nota2;
  int nota3;
} Aluno;

void newAluno(Aluno *aluno) {
  static int countMatriculas = 0;

  printf("Digite o nome do aluno (max 30): ");
  fflush(stdin);
  gets(aluno->nome);

  do {
    printf("Digite a nota 1: ");
    scanf("%d", &(aluno->nota1));
  } while(aluno->nota1 < 0 || aluno->nota1 > 10);
  do {
    printf("Digite a nota 2: ");
    scanf("%d", &(aluno->nota2));
  } while(aluno->nota2 < 0 || aluno->nota2 > 10);
  do {
    printf("Digite a nota 3: ");
    scanf("%d", &(aluno->nota3));
  } while(aluno->nota3 < 0 || aluno->nota3 > 10);

  aluno->matricula = countMatriculas++;
}

float calcularMedia(Aluno aluno) {
  return (float)(aluno.nota1 + aluno.nota2 + aluno.nota3) / 3.00;
}

void printAprovadoReprovado(Aluno aluno) {
  if(calcularMedia(aluno) >= 6) {
    printf("Aprovado.");
  } else {
    printf("Reprovado.");
  }
}

#define numAlunos 2

int main() {
  Aluno alunos[numAlunos];

  for(int i = 0; i < numAlunos; i++) {
    newAluno(&alunos[i]);
  }

  int matrMaiorNota = 0, matrMaiorMedia = 0, matrMenorMedia = 0;
  for(int i = 0; i < numAlunos; i++) {

    printf("O aluno %s foi ", alunos[i].nome);
    printAprovadoReprovado(alunos[i]);

    if(alunos[i].nota1 > alunos[matrMaiorNota].nota1)
      matrMaiorNota = i;

    if(calcularMedia(alunos[i]) > calcularMedia(alunos[matrMaiorMedia]))
      matrMaiorNota = i;

    if(calcularMedia(alunos[i]) < calcularMedia(alunos[matrMenorMedia]))
      matrMenorMedia = i;
  }

  printf("\nA matricula do aluno com a maior nota eh: %d", matrMaiorNota);
  printf("\nA matricula do aluno com a maior media eh: %d", matrMaiorMedia);
  printf("\nA matricula do aluno com a menor media eh: %d", matrMenorMedia);
}
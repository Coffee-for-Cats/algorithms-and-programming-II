#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu() {
  int escolha;
  printf("Escolha a opcao: ");
  printf("\n1- Inserir novo\n2- Contar vogais\n3- Nome do mais velho\n4- Sair\n");
  do {
    scanf("%d", &escolha);
  } while(escolha < 1 || escolha > 4);

  return escolha;
}

void inserirNovo() {
  char nome[20]; int idade;
  do {
    printf("Digite o nome: ");
    scanf("%s", nome);
    printf("Digite a idade: ");
    scanf("%d", &idade);
  } while(idade < 0);
  FILE* file = fopen("nomes.txt", "a+");
  fprintf(file, "%s;%d\n", nome, idade);
  fclose(file);
}

void contarVogais() {
  char linha[30]; int count = 0;
  FILE* file = fopen("nomes.txt", "r");
  while(fscanf(file, "%s", linha) != EOF) {
    for(int i = 0; i < strlen(linha); i++) {
      if(strchr("aeiou", linha[i])) count++;
    }
  }
  printf("Existem %d vogais no arquivo.", count);
  fclose(file);
}

void nomeMaisVelho() {
  char linha[30];
  FILE* file = fopen("nomes.txt", "r");
  while(fscanf(file, "%s", linha) != EOF) {
    char name[30];
    int i = 0;
    while(linha[i != ';']) {
      name[i] = linha[i];
    }
    i++;
    int age = atoi(linha + i);
    printf("%s -- %d", name, age);
  }
}

int main() {
  int escolha;
  do {
    escolha = menu();
    switch(escolha) {
      case 1: inserirNovo(); break;
      case 2: contarVogais(); break;
      case 3: nomeMaisVelho(); break;
    }
  } while(escolha != 4);
}
// 3) Peça ao usuário para digitar seus dados pessoais (Nome, Endereço, Data de Nascimento, Cidade, CEP, email), verifique se as informações de Data de Nascimento, CEP e email fazem sentido, e mostre ao usuário as informações, se estão todas corretas, ou  mostre que alguma informação está errada. Armazene, se correto os valores de entrada em uma struct.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
  char nome[20];
  char endereco[60];
  char cidade[40];
  char CEP[10];
  char email[40];
} User;

void myGets(char string[], char whatToGet[]) {
  printf("Digite o(a) %s: ", whatToGet);
  fflush(stdin);
  gets(string);
}

int consistCEP(char CEP[]) {
  int valid = 1;

  if(strlen(CEP) != 9) {
    valid = 0;
    printf("\nCEP de tamanho errado!\n");
  } else {
    if(CEP[5] != '-') {
      valid = 0;
      printf("\nPosicao incorreta do hifen no CEP!\n");
    } else {
      for(int i = 0; i < 5; i++) {
        if(CEP[i] < '0' && CEP[i] > '1') {
          valid = 0;
          printf("\nEncontrado letra no CPF antes\n");
          i += 10;
        }
      }
      for(int i = 6; i < 9; i++) {
        if(CEP[i] < '0' && CEP[i] > '1') {
          valid = 0;
          printf("\nEncontrado letra no CPF dps\n");
          i += 10;
        }
      }
    }
  }
  return valid;
}

int consistEmail(char email[]) {
  int valid = 1;

  char *placeOfAt = strchr(email, '@');
  
  if(  placeOfAt == NULL      // tem que ter @
    || placeOfAt - email == 0 // @ não pode ser o primeiro digito
    || placeOfAt[1] == '\0'   //@ não pode ser o ultimo digito
  ) valid = 0;

  return valid; 
}

void newUser(User *user) {
  myGets(user->nome, "nome");
  myGets(user->endereco, "endereco");
  myGets(user->cidade, "cidade");

  do {
    myGets(user->CEP, "CEP");
  } while(!consistCEP(user->CEP));
  
  do {
    myGets(user->email, "email");
  } while(!consistEmail(user->email));
}

#define numUsers 2

int main() {
  User users[numUsers];
  for(int i = 0; i < numUsers; i++) {
    newUser(&users[i]);
  }
}
#include <stdio.h>

int consistData(int dia, int mes, int ano) {
  int valid = 1;

  if(ano < 1900 || ano > 2024) {
    valid = 0;
    printf("Ano invalido");
  }

  if(dia < 1) {
    valid = 0;
    printf("Dia invalido");
  }

  switch(mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: 
      if(dia > 31) valid = 0;
      printf("\nDia inválido");
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if(dia > 30) valid = 0;
      printf("\nDia inválido");
      break;
    case 2:
      int limit = 28;
      if(ano % 4 == 0) limit++;
      if(dia > limit) valid = 0;
      printf("\nDia inválido");
      break;
    default:
      valid = 0;
      printf("\nMês invalido");
  }

  return valid;
}
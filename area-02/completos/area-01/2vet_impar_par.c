#include <stdio.h>

void par_impar(int vet1[], int vet2[]) {
  int paresTemp[24], countPar = 0;
  int imparesTemp[24], countImpar = 0;

  for(int i = 0; i < 12; i++) {
    if(vet1[i] % 2 == 0)
      paresTemp[countPar++] = vet1[i];
    else
      imparesTemp[countImpar++] = vet1[i];
  }

  for(int i = 0; i < 12; i++) {
    if(vet2[i] % 2 == 0)
      paresTemp[countPar++] = vet2[i];
    else
      imparesTemp[countImpar++] = vet2[i];
  }

  // printando só para verificar
  for(int i = 0; i < 12; i++) {
    //printf("%d ", paresTemp[i]);
    if(i < countPar)
      vet1[i] = paresTemp[i];
    else
      vet1[i] = 0;
  }
  printf("\n\n");
  for(int i = 0; i < 12; i++) {
    //printf("%d ", paresTemp[i]);
    if(i < countImpar)
      vet2[i] = imparesTemp[i];
    else
      vet2[i] = 0;
  }
}

int main() {
  int vet1_par[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int vet2_impar[12] = {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

  par_impar(vet1_par, vet2_impar);

  for(int i = 0; i < 12; i++) {
    printf("%d ", vet1_par[i]);
  }
  printf("\n");
  for(int i = 0; i < 12; i++) {
    printf("%d ", vet2_impar[i]);
  }
}
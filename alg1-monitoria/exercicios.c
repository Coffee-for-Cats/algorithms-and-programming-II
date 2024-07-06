// //Lista Exercícios Vetores
// Faça um programa que lê valores inteiros maiores que 10 em um vetor de 7 posições. Posteriormente crie um outro vetor com os elementos ímpares do vetor original. Ao final do programa imprima os dois vetores criados.

// Um fazendeiro deseja controlar o peso de seu pequeno rebanho de cabras, assim ele irá por 3 meses pesar cada um de seus 10 animais e registar o peso de cada um. Você irá criar um programa que possibilite estes registros mensais para as 10 cabras. O programa irá mostrar para cada animal a perda ou ganho de pesos nos três meses e identificar em qual mês o animal teve o maior peso. Informe, também, o peso total do rebanho no último mês e o valor da diferença entre o primeiro mês e o último mês do registro. 

#include <stdio.h>

#define TAM_REB 2
#define QTD_MESES 3

int main() {
  float pesos[QTD_MESES][TAM_REB];

  for(int i = 0; i < QTD_MESES; i++) {
    for(int j = 0; j < TAM_REB; j++) {
      printf("\nDigite o peso da cabra %d no mes %d: ", j + 1, i + 1);
      scanf("%f", &pesos[i][j]);
    }
  }

  for(int i = 0; i < TAM_REB; i++) {
    printf("\nCabra numero %d: ", i + 1);
    printf("\nPesos: %.2f | %.2f | %.2f ", pesos[0][i], pesos[1][i], pesos[2][i]);
    printf("\nDiferencas: %.2f | %.2f | %.2f ", 
      pesos[0][i],
      pesos[1][i] - pesos[0][i],
      pesos[2][i] - pesos[1][i]
    );

    // primeiro mês mais pesado
    if(pesos[0][i] > pesos[1][i] && pesos[0][i] > pesos[2][i]) {
      printf("\nA cabra estava mais pesada no primeiro mes");
    }

    // segundo mês mais pesado
    if(pesos[1][i] > pesos[0][i] && pesos[1][i] > pesos[2][i]) {
      printf("\nA cabra estava mais pesada no segundo mes");
    }

    // terceiro mês mais pesado
    if(pesos[2][i] > pesos[0][i] && pesos[2][i] > pesos[3][i]) {
      printf("\nA cabra estava mais pesada no terceiro mes");
    }
  }

  float pesoTotalUltimo = 0;
  for(int i = 0; i < TAM_REB; i++) {
    pesoTotalUltimo += pesos[QTD_MESES - 1][i];
  }
  printf("\nOs cabrito pesam junto %.2f kilos", pesoTotalUltimo);

  float pesoTotalPrimeiro = 0;
  for(int i = 0; i < TAM_REB; i++) {
    pesoTotalPrimeiro += pesos[QTD_MESES - 1][i];
  }
  printf("\nOs cabritos tiveram uma diferenca de peso de: %.2f", pesoTotalUltimo - pesoTotalPrimeiro);
}

// Faça um programa que armazena valores de salários dos últimos 5 meses de um funcionário. O funcionário pode receber a mais de um mês para outro maior, mas nunca menos. Informe ao final se o funcionário recebeu algum aumento e em que mês. Calcule o valor total recebido nos 5 meses.
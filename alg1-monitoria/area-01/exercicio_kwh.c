// Escreva um programa que leia o número de habitantes de uma determinada cidade, o valor do kwh e, para cada habitante, entre com os dados: consumo do mês e o código do consumidor (1: residencial, 2: comercial, 3: industrial). No nal, imprima o maior, o menor e a média de consumo dos habitantes e, por m, o total de consumo de cada categoria de consumidor.

#include <stdio.h>

int main() {
  // informações individuais de cada consumidor:
  int numHab, codigoConsumidor;
  float valorKwh, consumoMes;
  // somas:
  float maiorConsumo, menorConsumo, consumoResid = 0, consumoComerc = 0, consumoIndustr = 0;

  // informações da região
  do {
    printf("\nDigite o numero de habitantes: ");
    scanf("%d", &numHab);
  } while(numHab < 0);

  do {
    printf("\nDigite o valor do KWh: ");
    scanf("%f", &valorKwh);
  } while(valorKwh < 0.01);

  // # Informações de cada habitante
  for(int i = 0; i < numHab; i++) {
    printf("Habitante n %d", i + 1);

    do {
      printf("\nConsumo do mes: ");
      scanf("%f", &consumoMes);
    } while(consumoMes < 0);

    // na hora da prova questionem quais informações  
    // ela quer em R$ e quais ela quer em KWh
    consumoMes *= valorKwh;

    do {
      printf("\nCodigo do Consumidor: (1: residencial, 2: comercial, 3: industrial) ");
      scanf("%d", &codigoConsumidor);
    } while(codigoConsumidor < 1 || codigoConsumidor > 3);

    // atualiza as variaveis de maior e menor
    if (i == 0 || consumoMes > maiorConsumo) {
      maiorConsumo = consumoMes;
    }
    if (i == 0 || consumoMes < menorConsumo) {
      menorConsumo = consumoMes;
    }

    // faz a somagem em sua categoria:
    switch(codigoConsumidor) {
      case 1:
        consumoResid += consumoMes;
        break;
      case 2:
        consumoComerc += consumoMes;
        break;
      case 3:
        consumoIndustr += consumoMes;
        break;
    }
  }

  // é importante ter esse if, por que se "der uma dor de barriga" e a pessoa digitar
  // 0 como numHab, eu não posso printar variáveis vazias, por que vai printar
  // lixo de memória.
  if(numHab > 0) {
    // # Final da contagem, imprime os resultados: 
    printf("\nMaior: %.2f | Menor: %.2f", maiorConsumo, menorConsumo);
    // economiza 1 variável
    printf("\nMedia: %.2f", ((consumoResid + consumoComerc + consumoIndustr) / (float) numHab));
    printf("\nTotal de consumo Residencial: %.2f", consumoResid);
    printf("\nTotal de consumo Comercial: %.2f", consumoComerc);
    printf("\nTotal de consumo Industrial: %.2f", consumoIndustr);
  }
}
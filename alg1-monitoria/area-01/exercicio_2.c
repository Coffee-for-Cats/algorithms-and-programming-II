// Uma pesquisa está sendo realizada em uma praça, onde jovens se reúnem no final da tarde. O entrevistador deseja saber quantos jovens bebem energéticos. Para isso ele realiza as seguintes perguntas:
// - Idade;
// - Bebe energético (1 – sim, 2 – não)
//    - se bebe energético informe a quantidade por semana
// Para finalizar a pesquisa informe zero na idade do entrevistado. 
// Ao final da entrevista informe:
// - Quantidade de entrevistados;
// - menor idade entre os entrevistados;
// - maior idade entre as pessoas que bebem energético;
// - maior quantidade de energéticos que uma pessoa bebe por semana;
// - média das idades dos entrevistados;
// - média de energéticos consumidos por semana;
// - quantidade de jovens que não bebem energéticos.

#include <stdio.h>

int main() {
  int qtdEntrevistados = 0, qtdBebeEnergetico = 0;
  int maiorIdade, menorIdade, maiorQtdEnergetico;
  int somaIdades = 0, somaQtdEnerg = 0;

  int idade, bebeEnergetico, qtdEnergetico1sem, continuar;

  do {
    printf("\nVoce comecar a entrevistar as pessoas? (1- sim, 2- nao) ");
    scanf("%d", &continuar);
  } while(continuar < 1 || continuar > 2);
  
  while(continuar == 1) {
    do {
      printf("\nQuantos anos voce tem? ");
      scanf("%d", &idade);
    } while(idade < 0);

    do {
      printf("\nVoce bebe energetico? (1- sim, 2- nao) ");
      scanf("%d", &bebeEnergetico);
    } while(bebeEnergetico < 1 || bebeEnergetico > 2);

    if(bebeEnergetico == 1) {
      printf("\nQuanto energetico voce bebe em uma semana? ");
      scanf("%d", &qtdEnergetico1sem);
      qtdBebeEnergetico++;
    }

    if(idade < menorIdade || qtdEntrevistados == 0) {
      menorIdade = idade;
    }
    if(idade > maiorIdade || qtdEntrevistados == 0) {
      maiorIdade = idade;
    }
    if(qtdEnergetico1sem > maiorQtdEnergetico || qtdEntrevistados == 0) {
      maiorQtdEnergetico = qtdEnergetico1sem;
    }

    somaIdades += idade;
    somaQtdEnerg += qtdEnergetico1sem;
    qtdEntrevistados++;

    do {
      printf("\nVoce deseja entrevistar mais uma pessoa? (1- sim, 2- nao) ");
      scanf("%d", &continuar);
    } while(continuar < 1 || continuar > 2);
  }

  if(qtdEntrevistados > 0) {
    printf("\nQuantidade de entrevistados: %d", qtdEntrevistados);
    printf("\nMenor idade: %d | Maior idade: %d", menorIdade, maiorIdade);
    printf("\nMaior quantidade de energetico que uma pessoa bebe entre os entrevistados: %d", maiorQtdEnergetico);
    printf(
      "\nMedia das idades: %.2f",
      (float) somaIdades / (float) qtdEntrevistados
      );
    printf(
      "\nMedia dos energeticos consumidos/semana: %.2f",
      (float) somaQtdEnerg / (float) qtdBebeEnergetico
    );
    printf("\nQuantidade de pessoas que nao bebem energetico: %d", qtdEntrevistados - qtdBebeEnergetico);
  } else {
    printf("Nenhuma pessoa foi entrevistada!");
  }
}

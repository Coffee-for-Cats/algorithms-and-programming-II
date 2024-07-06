#include <stdio.h> 
int main ()
{
  /* 1)	Durante uma corrida de automóveis com N voltas de duração foram anotados para um piloto, na ordem, os tempos registrados em cada volta. 
  Fazer um programa em C para ler os tempos das N voltas, calcular e imprimir: 
  • melhor tempo; 
  • a volta em que o melhor tempo ocorreu;
  • tempo médio das N voltas. */
  int voltas, numMenorVolta;
  float tempo, menor, total;

  printf ("insira qtd de voltas: \n");
  scanf ("%i", &voltas);

  for (int n = 1; n <= voltas; n++) // n vai ser cada volta q vamos analisar
  {
    printf ("insira tempo da volta: \n");
    scanf ("%f", &tempo);

    total += tempo; // total de tempo
    
    if (n == 1) {
      menor = tempo;
      numMenorVolta = n;
    }
    else if (tempo < menor) {
      menor = tempo;
      numMenorVolta = n;
    }
  }

  float media = total/voltas;

  if(voltas > 0) {
    printf ("media de tempo entre as voltas %2.f\n", media); 
    printf ("melhor tempo foi %2.f e ocorreu na volta %i", menor, numvolta);
  } else {
    printf("Nenhuma volta medida!");
  }
}
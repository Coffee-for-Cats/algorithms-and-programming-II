//Faça um programa que leia um conjunto não determinado de valores, um de cada vez, e escreva para cada um dos valores lidos, o quadrado, o cubo e a raiz quadrada. Finalize a entrada de dados com um valor negativo ou zero.

#include <stdio.h>
#include <math.h>

int main() {
  float num;

  printf("Digite um numero: ");
  scanf("%f", &num);

  while(num > 0) {
    // printa as infos que a sora quer.
    printf("\nO quadrado do numero eh: %.2f", num * num);
    printf("\nO cubo do numero eh: %.2f", pow(num, 3));
    printf("\nA raiz quadrada do numero eh: %.6f", sqrt(num));

    // fiz a pergunta no final de propósito...
    // dessa forma ele não vai printar as infos quando o número for <= 0
    printf("\nDigite um numero: ");
    scanf("%f", &num);
  }

  printf("Programa encerrado!");
}
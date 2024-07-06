#include <stdio.h>

int main() {
  int i, j;
  int num = -1;
  while(num < 0) {
    printf("Digite o tamanho do cubao: ");
    scanf("%d", &num);
  }

  for(i = 1; i <= num; i++) 
  {
    for(j = 1; j <= num; j++) 
    {
      if(i == 1 || i == num || j == 1 || j == num)
        printf("* ");
      else
        printf("  ");
    }
    printf("\n");
  }
}
#include <stdio.h>

int horasMinSeg(int numSeg, int *horas, int *min, int *seg) {
  *min   = numSeg / 60;
  *seg    = numSeg % 60;

  *horas = *min / 60;
  *min %= 60;
}

int main() {
  int num1;
  printf("Segundos: ");
  scanf("%d", &num1);


  int horas;
  int min;
  int seg;
  horasMinSeg(num1, &horas, &min, &seg);
  printf("%d:%d:%d", horas, min, seg);
}
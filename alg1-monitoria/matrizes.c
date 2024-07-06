#include <stdio.h>

#define tam 5

int main() {
  int mat[5][5];
  int count = 0;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      mat[i][j] = count++;
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }

  printf("%d", mat[0][3]);
}
#include <stdio.h>

void troca(int array[], int a, int b) {
  int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}

void bubble_sort(int array[], int size) {
  for(int i = size - 1; i > 0; i--)
    for(int j = 0; j < i; j++)
      if(array[i] < array[j])
        troca(array, i, j);
}

int main() {
  int array[10] = {15, 40, 7, 12, 8, 9, -2, 17, 4, 3};

  bubble_sort(array, 10);

  for(int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
}
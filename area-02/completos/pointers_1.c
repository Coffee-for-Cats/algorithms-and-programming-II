#include <stdio.h>

void changeEvens(int *arr) {
  for(int i = 0; i < 5; i++) {
    // is even
    if(arr[i] % 2 == 0) {
      arr[i] = 1;
    }
  }
}

int main() {
  int arr[5];
  for(int i = 0; i < 5; i++) {
    printf("\nWrite the number %dth: ", i);
    scanf("%d", &arr[i]);
  }

  changeEvens(arr);

  printf("Arr:\n");
  for(int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
}

// 3 de julho aniver andreza
#include <stdio.h>
#include <stdlib.h>

int birthdayCakeCandles(int ar_size, int* ar) {
  int max = -1;
  int counter;

  for(int i = 0; i < ar_size; i++) {
    if(ar[i] > max) {
      max = ar[i];
      counter = 1;
    } else {
      counter += (ar[i] == max);
    }
  }

  return counter;
}

int main() {
  int n;
  scanf("%i", &n);
  int *ar = malloc(sizeof(int) * n);

  for(int ar_i = 0; ar_i < n; ar_i++){
    scanf("%i",&ar[ar_i]);
  }

  int result = birthdayCakeCandles(n, ar);
  printf("%d\n", result);

  return 0;
}

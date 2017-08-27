#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p, const void *q) {
  int a = *(const int *)p;
  int b = *(const int *)q;

  return b - a;
}

int birthdayCakeCandles(int n, int ar_size, int* ar) {
  int counter = 1;
  qsort(ar, n, sizeof(int), cmp);

  for(int i = 1; i < ar_size; i++) {
    if(ar[i] == ar[0]) {
      counter++;
    } else {
      break;
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
  int result = birthdayCakeCandles(n, n, ar);
  printf("%d\n", result);
  return 0;
}

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* funnyString(char* s) {
  int len = strlen(s);

  for(int i = 1, j = len - 1; i < len; i++, j--) {
    if(abs(s[i] - s[i - 1]) != abs(s[j] - s[j - 1]))
      return "Not Funny";
  }

  return "Funny";
}

int main() {
  int n;
  scanf("%i", &n);

  for(int i = 0; i < n; i++){
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);

    char* result = funnyString(s);
    printf("%s\n", result);
  }

  return 0;
}

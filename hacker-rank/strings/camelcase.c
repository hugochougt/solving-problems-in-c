#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  int counter = 1;
  char* s = (char *)malloc(100240 * sizeof(char));
  scanf("%s", s);

  for(int i = 0; s[i] != '\0'; i++) {
    if(isupper(s[i])) {
      counter++;
    }
  }

  printf("%i\n", counter);
  return 0;
}

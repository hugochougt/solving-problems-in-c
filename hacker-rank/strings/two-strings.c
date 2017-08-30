#include <stdio.h>
#include <stdlib.h>

char* twoStrings(char* s1, char* s2) {
  char alphabet[26] = {0};

  for(int i = 0; s1[i] != '\0'; i++) {
    int a1_i = s1[i] - 'a';
    if(alphabet[a1_i] == 0) {
      alphabet[a1_i]++;
    }
  }

  for(int j = 0; s2[j] != '\0'; j++) {
    int a2_i = s2[j] - 'a';
    if(alphabet[a2_i] == 1) {
      return "YES";
    }
  }

  return "NO";
}

int main() {
  int q;
  scanf("%i", &q);

  for(int a0 = 0; a0 < q; a0++) {
    char* s1 = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s1);
    char* s2 = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s2);
    int result_size;
    char* result = twoStrings(s1, s2);
    printf("%s\n", result);
  }

  return 0;
}

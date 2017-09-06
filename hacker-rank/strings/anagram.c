#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LEN 26

int anagram(char* s){
  int len = strlen(s);
  if(len % 2 == 1) {
    return -1;
  }

  int mid = len / 2;
  int a1[ALPHABET_LEN] = {0};
  int a2[ALPHABET_LEN] = {0};

  for(int i = 0; i < mid; i++)
    a1[s[i] - 'a']++;
  for(int i = mid; i < len; i++)
    a2[s[i] - 'a']++;

  int counter = 0;
  for(int i = 0; i < ALPHABET_LEN; i++)
    counter += abs(a1[i] - a2[i]);

  return counter / 2;
}

int main() {
  int q;
  scanf("%i", &q);

  for(int a0 = 0; a0 < q; a0++){
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);

    printf("%d\n", anagram(s));
  }

  return 0;
}

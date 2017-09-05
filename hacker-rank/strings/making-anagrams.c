#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_LEN 26

int makingAnagrams(char* s1, char* s2){
  int a1[ALPHABET_LEN] = {0};
  int a2[ALPHABET_LEN] = {0};

  for(int i = 0; s1[i] != '\0'; i++)
    a1[s1[i] - 'a']++;
  for(int i = 0; s2[i] != '\0'; i++)
    a2[s2[i] - 'a']++;

  int counter = 0;
  for(int i = 0; i < ALPHABET_LEN; i++) {
    counter += abs(a1[i] - a2[i]);
  }

  return counter;
}

int main() {
  char* s1 = (char *)malloc(512000 * sizeof(char));
  char* s2 = (char *)malloc(512000 * sizeof(char));
  scanf("%s", s1);
  scanf("%s", s2);

  int result = makingAnagrams(s1, s2);
  printf("%d\n", result);

  return 0;
}

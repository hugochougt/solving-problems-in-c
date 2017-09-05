#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 26

char* gameOfThrones(char* s){
  int arr[MAX_LEN] = {0};
  for(int i = 0; s[i] != '\0'; i++) {
    arr[s[i] - 'a']++;
  }

  int odd = 0;
  for(int i = 0; i < MAX_LEN; i++) {
    odd += arr[i] % 2;
  }

  if(odd <= 1) {
    return "YES";
  } else {
    return "NO";
  }
}

int main() {
  char* s = (char *)malloc(512000 * sizeof(char));
  scanf("%s", s);
  printf("%s\n", gameOfThrones(s));
  return 0;
}

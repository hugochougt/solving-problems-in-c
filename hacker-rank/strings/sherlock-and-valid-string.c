#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_LEN 26

/* The logic of the solution is as follows: count the character counts for each character. */
/* 1. if they are all equal – it means that all characters occur exactly N times and there is no removal needed */
/* 2. if exactly 1 char has a different count than all other characters – remove this char completely and S is fixed. */
/* 3. if 2 or more have less or more characters – there is no way to fix the string in just 1 removal */
/* Solution in Python: https://www.martinkysel.com/hackerrank-sherlock-and-valid-string-solution/ */

char* isValid(char* s){
  int arr[ALPHABET_LEN] = {0};
  int diff = 0;
  int first = 0;
  int one_counter = 0;
  int odd = 0;
  int max = -1;
  int len;

  for(len = 0; s[len] != '\0'; len++) {
    arr[s[len] - 'a']++;
  }

  for(int i = 0; i < ALPHABET_LEN; i++) {
    if(arr[i] != 0) {

      if(arr[i] == 1)
        one_counter++;

      if(arr[i] % 2 == 1)
        odd++;

      if(max < arr[i])
        max = arr[i];

      if(first == 0) {
        first = arr[i];
      } else {
        if(first != arr[i]) {
          diff = 1;
        }
      }
    }
  }

  if(diff == 0)
    return "YES";

  if(one_counter == 1)
    return "YES";

  int flag = 0;
  for(int i = 0; i < ALPHABET_LEN; i++) {
    if((arr[i] != 0) && ((max - arr[i]) > 1))
      flag = 1;
  }
  if((flag == 0) && (odd % 2 == 1))
    return "YES";

  return "NO";
}

/*
  Test case:
  1. aabbcc
  2. aabc
  3. aaabbbcccdddn
  4. bbacdd
  5. abbac
  6. ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd
*/

int main() {
  char* s = (char *)malloc(512000 * sizeof(char));
  scanf("%s", s);

  char* result = isValid(s);
  printf("%s\n", result);

  return 0;
}

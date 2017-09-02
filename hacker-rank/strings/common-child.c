#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 5001

int commonChild(char* s1, char* s2){
    int n = strlen(s1);
    int m = strlen(s2);
    // We need to use a staticly allocated array
    // or we will run out of stack space (results in a segmentation fault)
    static int lcs[MAX_LENGTH][MAX_LENGTH];

    for(int i = 0; i <= n; i++) {
        lcs[i][0] =  0;
    }
    for(int j = 0; j <= m; j++) {
        lcs[0][j] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2 [j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else if (lcs[i - 1][j] >= lcs[i][j - 1]) {
                lcs[i][j] = lcs[i - 1][j];
            } else {
                lcs[i][j] = lcs[i][j - 1];
            }
        }
    }

    return lcs[n][n];
}

int main() {
    char* s1 = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s1);
    char* s2 = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s2);

    int result = commonChild(s1, s2);
    printf("%d\n", result);

    return 0;
}

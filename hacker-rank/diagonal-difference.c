#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, primary_diagonal = 0, secondary_diagonal = 0;
    scanf("%d", &n);
    int m[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
            if (i == j) {
                primary_diagonal += m[i][j];
            }
            if (i + j == n - 1) {
                secondary_diagonal += m[i][j];
            }
        }
    }
    printf("%d\n", abs(primary_diagonal - secondary_diagonal));

    return 0;
}

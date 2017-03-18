#include <stdio.h>

int main() {
    int n, t, zero = 0, positive = 0, negative = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t > 0) {
            positive++;
        } else if (t < 0) {
            negative++;
        } else {
            zero++;
        }
    }
    printf("%.6f\n", (float)positive / n);
    printf("%.6f\n", (float)negative/ n);
    printf("%.6f\n", (float)zero/ n);

    return 0;
}

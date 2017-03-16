#include <stdio.h>

int main(){
    int a0, a1, a2;
    int b0, b1, b2;
    int point_a = 0, point_b = 0;

    scanf("%d %d %d", &a0, &a1, &a2);
    scanf("%d %d %d", &b0, &b1, &b2);

    if (a0 > b0) {
        point_a++;
    } else if (a0 < b0) {
        point_b++;
    }
    if (a1 > b1) {
        point_a++;
    } else if (a1 < b1) {
        point_b++;
    }
    if (a2 > b2) {
        point_a++;
    } else if (a2 < b2) {
        point_b++;
    }

    printf("%d %d\n", point_a, point_b);

    return 0;
}

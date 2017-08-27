#include <stdio.h>
#include <limits.h>

int main() {
    long num, min = LONG_MAX, max = LONG_MIN, sum = 0;
    int i;
    for (i = 0; i < 5; i++) {
        scanf("%ld", &num);
        sum += num;
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }
    printf("%ld %ld\n", sum - max, sum - min);

    return 0;
}

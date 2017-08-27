#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    long long m, sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld", &m);
        sum += m;
    }
    printf("%lld\n", sum);
    return 0;
}

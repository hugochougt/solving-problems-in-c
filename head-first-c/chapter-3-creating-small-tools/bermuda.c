#include <stdio.h>
#include <unistd.h>

int main() {
    float latitude, longitude;
    char info[80];

    while(scanf("%f, %f, %79[^\n]", &latitude, &longitude, info) == 3) {
        if (((latitude > 26) && (latitude < 34)) &&
            ((longitude > -76) && (longitude < -64))) {
            printf("%f,%f,%s\n", latitude, longitude, info);
        }
    }
}

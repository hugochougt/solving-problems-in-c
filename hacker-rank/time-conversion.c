#include <stdio.h>

int main() {
    char time[11];
    int hour;

    scanf("%s", time);
    hour = (time[0] - '0') * 10 + (time[1] - '0');
    if (hour < 12 && time[8] == 'P')
        hour += 12;
    if (hour == 12 && time[8] == 'A')
        hour = 0;
    time[0] = hour / 10 + '0';
    time[1] = hour % 10 + '0';
    time[8] = '\0';

    printf("%s\n", time);

    return 0;
}

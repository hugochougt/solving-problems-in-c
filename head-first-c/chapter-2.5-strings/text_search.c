#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 81

char tracks[][MAX_LENGTH] = {
    "I left my heart in Harvard Med School",
    "Newark, Newark - a wonderful town",
    "Dancing with a Dork",
    "From here to maternity",
    "The girl from Iwo Jima"
};

void find_track(char search_for[]) {
    int i;
    for(i = 0; i < 5; i++) {
        if(strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

int main() {
    char search_for[MAX_LENGTH];

    printf("Enter your search: ");
    scanf("%s", search_for);

    find_track(search_for);

    return 0;
}

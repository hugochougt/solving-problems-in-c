#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    char* paths[] = {
        "/",
        "/tmp",
        "."
    };
    int i;
    for(i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
        }
        if (!pid) {
            if (execlp("ls", "ls", paths[i], NULL) == -1) {
                fprintf(stderr, "Can't run script: %s\n", strerror(errno));
                return 1;
            }
        }
    }
    return 0;
}

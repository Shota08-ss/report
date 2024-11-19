#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Received SIGTERM signal\n");
    exit(1);
}

int main(void) {
    signal(SIGTERM, signal_handler);

    printf("Process ID: %d\n", getpid());

    while (1) {
        sleep(1);
    }
    return 0;
}


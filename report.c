#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// SIGINT用のハンドラ
void sigint_handler(int signum) {
    printf("Received SIGINT signal\n");
}

// SIGUSR1用のハンドラ
void sigusr1_handler(int signum) {
    printf("Received SIGUSR1 signal\n");
}

int main(void) {
    struct sigaction sa_int, sa_usr1;

    // SIGINT用ハンドラの登録
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_handler = sigint_handler;
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);

    // SIGUSR1用ハンドラの登録
    sigemptyset(&sa_usr1.sa_mask);
    sa_usr1.sa_handler = sigusr1_handler;
    sa_usr1.sa_flags = 0;
    sigaction(SIGUSR1, &sa_usr1, NULL);

    printf("Process ID: %d\n", getpid());

    // シグナルが送られるまで無限ループ
    while (1) {
        sleep(1);
    }
    return 0;
}

//update1
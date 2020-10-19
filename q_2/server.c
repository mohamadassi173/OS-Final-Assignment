#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

static int count = 0;

void SIGINT_handler (int signal) {
    count++;
}
void SIGUSR1_handler (int signal) {
    printf("The server got %d SIGINT.\n", count);
}

int main() {
    printf("Server is running, The server pid is %d\n", getpid());
    signal(SIGUSR1, SIGINT_handler);
    signal(SIGINT, SIGUSR1_handler);
    while(1){}
    return 0;
}

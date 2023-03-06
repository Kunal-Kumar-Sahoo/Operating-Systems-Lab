#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if(pid == 0) {
        printf("I am child process. My Process ID: %d\n", getpid());
        printf("My parent's Process ID: %d\n", getppid());
        printf("Child terminates\n");
        exit(0);
    }
    else {
        printf("I am parent process. My Process ID: %d\n", getpid());
        printf("My parent's Process ID: %d\n", getppid());
        printf("Parent terminates\n");
    }
    return 0;
}

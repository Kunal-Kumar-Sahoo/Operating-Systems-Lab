#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if(pid == 0) {
        printf("I am Child process. My Process ID: %d\n", getpid());
        printf("My Parent's Process ID: %d\n", getppid());
        sleep(30);
        printf("After sleeping my Process ID: %d\n", getpid());
        printf("After sleeping my Parent's Process ID: %d\n", getppid());
        printf("Child terminates\n");
        exit(0);
    }
    else {
        sleep(20);
        printf("I am Parent. My Process ID: %d\n", getpid());
        printf("My Parent's Process ID: %d\n", getppid());
        printf("Parent terminates\n");
    }
    return 0;
}

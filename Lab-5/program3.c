#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkexample() {
    if(fork() == 0)
        printf("Hello, from the child\n");
    else 
        printf("Hello, from the parent\n");
}

int main() {
    forkexample();
    return 0;
}

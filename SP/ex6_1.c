#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char **argv)
{
    int pid = fork();
    int pid2 = fork();
    printf("pid: %d and parent: %d\n",getpid(),getppid());
    return 0;
}
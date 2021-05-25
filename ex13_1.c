#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int pid;
    int workPid;
    pid = fork();
    if (pid == -1)
    {
        perror("Bad fork");
        exit(0);
    }
    else if (pid > 0)
    {
        printf("Parent pid: %d\n", getpid());
    }
    else
    {
        sleep(3);
        printf("Child pid: %d\n", getpid());
        workPid = 0;
    }
    printf("WOrking... from %d\n", getpid());

    return 0;
}
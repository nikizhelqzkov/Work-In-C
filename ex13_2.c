#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int pid;
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
        int workPid = 0;
        while (workPid <= 500000000)
        {
            workPid = workPid + 1;
        }

        printf("Child pid: %d\n", getpid());
    }
    printf("WOrking... from %d\n", getpid());
    exit(1);

    return 0;
}
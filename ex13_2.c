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
        exit(1);
    }
    else if (pid > 0)
    {
        printf("Parent pid: %d\n", getpid());
    }
    else
    {
        int waiter = 0;
        while (waiter <= 500000000)
        {
            waiter = waiter + 1;
        }
        printf("\n");

        printf("Child pid: %d\n", getpid());
    }
    printf("WOrking... from %d\n", getpid());

    return 0;
}
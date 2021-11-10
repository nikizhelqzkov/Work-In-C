#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char **argv)
{
    int status;
    int pid = fork();
    if (pid == -1)
    {
        printf("Error");
        exit(1);
    }
    else if (pid > 0)
    {
        int fPid = wait(&status);

        if (status != 0)
        {
            printf("Error -1");
        }
        else
        {
            printf("%d", fPid);
        }
    }
    else
    {
        int pid2 = fork();
        if (pid2 > 0)
        {
            exit(execlp(argv[1], argv[1], (char *)0));
        }
        else if (pid2 == 0)
        {
            exit(execlp(argv[2], argv[2], (char *)0));
        }
        else
        {
            printf("error");
            exit(1);
        }
    }

    return 0;
}
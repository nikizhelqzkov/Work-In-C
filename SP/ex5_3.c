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
    int status;
    if (pid > 0)
    {
        wait(&status);
        if (status == 0)
        {
            printf("Successfully execute %s", argv[1]);
        }
    }
    else
    {
        exit(execlp(argv[1], argv[1], (char *)0));
    }

    return 0;
}
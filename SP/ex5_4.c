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
    char **buf = (char **)malloc((argc) * sizeof(char));
    for (int i = 2; i < argc; i++)
    {
        buf[i - 2] = argv[i];
    }

    if (pid > 0)
    {
        wait(&status);
        if (status == 0)
        {
            printf("Successfully execute %s with code: %d", argv[1], status);
        }
        else
        {
            printf("UnSuccessfully execute %s with code: %d", argv[1], status);
        }
    }
    else
    {
        exit(execvp(argv[1], buf));
    }

    return 0;
}
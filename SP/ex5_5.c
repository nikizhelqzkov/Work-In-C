#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("Not enough args");
        exit(1);
    }
    else if (argc > 4)
    {
        printf("Too much args");
        exit(1);
    }
    for (int i = 1; i <= 3; i++)
    {
        int status;
        int pid = fork();

        if (pid > 0)
        {
            int process = wait(&status);
            printf("Process number %d with code %d\n", process, status);
        }
        else
        {
            exit(execlp(argv[i], argv[i], (char *)0));
        }
    }

    return 0;
}
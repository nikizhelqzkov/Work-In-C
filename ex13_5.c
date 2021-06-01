#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int pid[2];
    pid[0] = fork();
    int status1, status2;
    if (pid[0] == -1)
    {
        perror("Bad fork");
        exit(-1);
    }
    else if (pid[0] > 0)
    {
        wait(&status1);

        pid[1] = fork();

        if (pid[1] == -1)
        {
            perror("newpid");
            exit(-1);
        }
        else if (pid[1] > 0)
        {
            wait(&status2);
        }
        else
        {
            exit(execlp(argv[2], argv[2], 0));
        }
    }

    else
    {
        exit(execlp(argv[1], argv[1], 0));
    }
    printf("\nResult : %d \n", !status1 && !status2);
    return 0;
}
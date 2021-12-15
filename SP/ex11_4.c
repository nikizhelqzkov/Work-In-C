#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

int main(int argc, char **argv)
{
    char **buf = (char **)malloc((argc) * sizeof(char));
    for (int i = 2; i < 4; i++)
    {
        buf[i - 2] = argv[i];
    }

    char **buf2 = (char **)malloc((argc) * sizeof(char));
    for (int i = 4; i < argc; i++)
    {
        buf2[i - 4] = argv[i];
    }

    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (pid > 0)
    {
        int status;
        wait(&status);
        if (status == 0)
        {
            close(0);
            dup(fd[0]);
            close(fd[1]);
            close(fd[0]);
            execvp(argv[4], buf2);
        }
    }
    else if (pid == 0)
    {
        int fd2[2];
        pipe(fd2);
        pid_t pid2 = fork();
        if (pid2 > 0)
        {
            int status;
            wait(&status);
            if (status == 0)
            {
                close(1);
                dup(fd[1]);
                close(0);
                dup(fd2[0]);
                close(fd2[0]);
                close(fd2[1]);
                execvp(argv[2], buf);
            }
        }
        else if (pid2 == 0)
        {
            close(1);
            dup(fd2[1]);
            close(fd2[1]);
            close(fd2[0]);
            execlp(argv[1], argv[1], (char *)0);
        }
    }

    return 0;
}
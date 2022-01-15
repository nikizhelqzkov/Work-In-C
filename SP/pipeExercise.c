#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char **argv)
{
    pid_t pid2 = fork();
    if (pid2 > 0)
    {
        int status;
        wait(&status);
        if (status != 0)
        {
            perror("Unsuccessful working with pipe");
            exit(1);
        }
        execlp("mv", "mv", argv[1], "/procinfo", (char *)0);
    }
    else if (pid2 == 0)
    {
        int f = open(argv[1], O_RDWR | O_APPEND | O_CREAT, 0666);
        if (f == -1)
        {
            perror("Error with open");
            exit(1);
        }

        int fd[2];
        pipe(fd);
        pid_t pid = fork();
        if (pid > 0)
        {
            close(1);
            dup(fd[1]);
            close(fd[1]);
            close(fd[0]);
            execlp("ps", "ps", "aux", (char *)0);
        }
        else if (pid == 0)
        {
            close(0);
            dup(fd[0]);
            close(1);
            dup(f);
            close(f);
            close(fd[0]);
            close(fd[1]);
            execlp("grep", "grep", "vi", (char *)0);
        }
    }
    return 0;
}

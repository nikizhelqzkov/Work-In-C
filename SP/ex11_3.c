#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char **buf = (char **)malloc((argc) * sizeof(char));
    for (int i = 2; i < argc; i++)
    {
        buf[i - 2] = argv[i];
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
        execlp(argv[1], argv[1], (char *)0);
    }
    else if (pid == 0)
    {
        close(0);
        dup(fd[0]);
        close(fd[1]);
        close(fd[0]);
        execvp(argv[2],buf);
    }

    return 0;
}
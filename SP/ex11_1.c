#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (pid > 0)
    {
        close(1);
        dup(fd[1]);
        close(fd[1]);
        close(fd[0]);
        execlp("who", "who", (char *)0);
    }
    else if (pid == 0)
    {
        close(0);
        dup(fd[0]);
        close(fd[1]);
        close(fd[0]);
        execlp("wc", "wc", "-l", (char *)0);
    }

    return 0;
}
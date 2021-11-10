#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    int fd2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    int fd3 = dup(fd2);
    int res = dup(1);
    int pid = fork();
    int status;
    if (pid == 0)
    {
        dup2(fd2, 1);
        dup2(res,fd2);
        exit(0);
    }
    else if (pid > 0)
    {
        wait(&status);
        dup2(res,1);
    }
    else
    {
        printf("ERRROOORR");
        exit(1);
    }
    write(res, "hello3", 6);
    write(fd3, "hello4", 6);
    
    return 0;
}
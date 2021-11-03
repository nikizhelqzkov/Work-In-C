#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char **argv)
{
    int fd = open("gpza", O_CREAT | O_TRUNC | O_WRONLY, 0666);
    int fd2 = open("gpza", O_CREAT | O_TRUNC | O_WRONLY, 0666);
    int pid = fork();
    if (pid > 0)
    {
        printf("%d", getpid());
    }
    write(fd, "Hello1", 6);
    write(fd2, "Hello2", 6);
    return 0;
}
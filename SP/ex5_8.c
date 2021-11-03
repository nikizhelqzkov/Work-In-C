#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0666);
    int status;
    int pid = fork();
    char str[1];
    if (pid > 0)
    {
        int process = wait(&status);
        lseek(fd, 0, 0);
        int c;
        while ((c = read(fd, str, 1)) > 0)
        {
            write(1, str, 1);
            write(1, " ", 1);
        }
    }
    else
    {
        write(fd, "Hello", 5);
    }

    return 0;
}
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd = open("abc", O_CREAT | O_WRONLY | O_APPEND, 0666);
    int pid = fork();
    char str[5] = "hello";
    printf("System pid: %d\n", getpid());
    write(fd, str, 5);
    close(fd);
    return 0;
}
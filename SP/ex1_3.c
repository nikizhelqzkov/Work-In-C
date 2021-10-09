#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0666);
    while (1)
    {
        char *buf = (char *)calloc(100, sizeof(char));
        read(0, buf, 100);
        write(fd, buf, strlen(buf));
        free(buf);
    }
    close(fd);
    return 0;
}
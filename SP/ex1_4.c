#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        int fd = open(argv[i], O_WRONLY | O_CREAT, 0666);
        close(fd);
    }
    while (1)
    {
        char *buf = (char *)calloc(100, sizeof(char));
        read(0, buf, 100);
        for (int i = 1; i < argc; ++i)
        {
            int fd = open(argv[i], O_WRONLY | O_APPEND);
            write(fd, buf, strlen(buf));
            close(fd);
        }
        free(buf);
    }
    return 0;
}
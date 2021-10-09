#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    char *buf = (char *)calloc(100, sizeof(char));
    if (fd == -1)
    {
        printf("No such file %s", argv[1]);
        return -1;
    }
    int sz = read(fd, buf, 100);
    close(fd);
    fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
    write(fd, buf, strlen(buf));
    close(fd);
    return 0;
}
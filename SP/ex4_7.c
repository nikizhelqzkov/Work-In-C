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
    int size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    int fdres = dup2(fd,0);
    int sz = read(0, buf, size);
    close(fd);
    fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
    fdres = dup2(fd,1);
    write(1, buf, strlen(buf));
    close(fd);
    return 0;
}
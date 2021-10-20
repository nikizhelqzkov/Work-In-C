#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd1, fd2;
    fd1 = open("f1", O_RDWR);
    fd2 = open("f1", O_RDWR);

    int size = lseek(fd1, -2, SEEK_END) + 2;
    write(fd1, "wxyz", 4);
    lseek(fd1, 4, SEEK_SET);
    write(fd1, "12", 2);

    char *buf = (char *)calloc(size+1, sizeof(char));
    read(fd2, buf, size);
    write(1, buf, size);
    return 0;
}
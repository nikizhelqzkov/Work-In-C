#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd = open("bb", O_RDONLY);
    if (fd < 0)
    {
        printf("Error with open");
    }
    char *buf = (char *)malloc(sizeof(char) * 16);
    for (int i = 8; i >= 0; i--)
    {
        int len = read(fd, buf, 1);
        write(1, buf, 1);
    }

    close(fd);
    return 0;
}
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error with open");
    }
    char *buf = (char *)malloc(sizeof(char) * 16);
    for (int i = 5; i >= 0; i--)
    {
        int len = read(fd, buf, 1);
        printf("%s\n", buf);
    }

    close(fd);
    return 0;
}
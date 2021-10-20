#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd = open("aa", O_RDONLY);
    if (fd < 0)
    {
        printf("Error with open");
    }
    char *buf = (char *)malloc(sizeof(char) * 16);
    printf("1)--------------------\n");
    for (int i = 5; i >= 0; i--)
    {
        lseek(fd, 0, 0);
        int len = read(fd, buf, 1);
        printf("%s\n", buf);
    }
    printf("2)--------------------\n");
    for (int i = 5; i >= 0; i--)
    {
        lseek(fd, 3, 0);
        int len = read(fd, buf, 1);
        printf("%s\n", buf);
    }
    printf("3)--------------------\n");
    for (int i = 5; i >= 0; i--)
    {
        lseek(fd, 3, SEEK_CUR);
        int len = read(fd, buf, 1);
        printf("%s\n", buf);
    }
    printf("4)--------------------\n");
    for (int i = 5; i >= 0; i--)
    {
        int len = read(fd, buf, 1);
        printf("%s\n", buf);
    }

    close(fd);
    return 0;
}
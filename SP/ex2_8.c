#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0)
    {
        printf("Error with open");
        return -1;
    }
    char *buf = (char *)malloc(sizeof(char) * 100);
    for (int i = 0; i < 25; i++)
    {
        buf[i] = 'a' + i;
    }
    int len = write(fd, buf, 25);
    printf("writed %d \n", len);
    close(fd);
    fd = open(argv[1], O_RDONLY);
    free(buf);
    buf = (char *)malloc(sizeof(char) * 100);
    int readLen;
    while ((readLen = read(fd, buf, 15)) > 0)
    {
        printf("Readed %d : %s \n", readLen,buf);
    }
    free(buf);
    close(fd);
    return 0;
}
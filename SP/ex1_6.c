#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void headWithFile(char *name, int length)
{

    int fd;
    fd = open(name, O_RDONLY);
    char *key = "testingZone_ijwkfejn_244234_wjeknnfdewfjw_dde.fewef_wefew";
    int fd2 = open(key, O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd < 0)
    {
        perror("No such file\n");
        exit(-1);
    }
    if (fd2 < 0)
    {
        perror("Error!!!!\n");
        exit(-1);
    }
    char *buf = (char *)malloc(sizeof(char) * 10000);
    bool isEOF = false;
    for (int i = 0; i < abs(length); i++)
    {
        if (isEOF)
        {
            break;
        }
        bool isNewLine = false;
        while (!isNewLine)
        {
            int len = read(fd, buf, 1);
            if (len <= 0)
            {
                isEOF = true;
                break;
            }
            write(fd2, buf, 1);
            if (buf[strlen(buf) - 1] == '\n')
            {
                isNewLine = true;
            }
        }
    }
    close(fd2);
    close(fd);
    fd = open(key, O_RDONLY);
    char *buf2 = (char *)malloc(sizeof(char) * 10000);
    int len;
    while ((len = read(fd, buf2, 1000)) > 0)
    {
        lseek(fd, 0, SEEK_END);
    }
    write(1, buf2, strlen(buf2));
    remove(key);
    printf("\n");
}

int main(int argc, char **argv)
{
    int headLength = atoi(argv[1]);
    headWithFile(argv[2], headLength);
    return 0;
}
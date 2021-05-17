#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd;
    char *buf;
    buf = (char *)malloc(sizeof(char) * (100));
    fd = open(argv[1], O_RDONLY);
    int r;
    r = read(fd, buf, 100);
    close(fd);
    int index = 0;
    char *newbuf = (char *)malloc(sizeof(char) * (100));
    for (int i = 0; i < 3; i++)
    {
        newbuf[i] = buf[i];
    }
    int pos = 3;
    for (int i = 3; i < strlen(buf); i++)
    {
        if (buf[i] == '\n')
        {
            index = i;

            if (index + 3 < strlen(buf))
            {
                ++i;
                for (int j = index + 1; j <= index + 3; j++)
                {
                    newbuf[pos] = buf[j];
                    ++pos;
                    ++i;
                }
            }
        }
    }
    printf("%s\n", newbuf, pos);
    fd = open(argv[2], O_WRONLY | O_APPEND);
    int len = write(fd, newbuf, strlen(newbuf));
    return 0;
}
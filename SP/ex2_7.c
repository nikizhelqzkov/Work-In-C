#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    int fd = open("aa", O_RDONLY);
    if (fd < 0)
    {
        printf("Error with open");
    }
    char *buf = (char *)malloc(sizeof(char) * 16);
    execlp("wc", "wc","-c",argv[1], (char *)0);

    close(fd);
    return 0;
}
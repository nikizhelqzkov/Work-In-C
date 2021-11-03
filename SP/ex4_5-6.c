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
        printf("ERROR with Open");
        exit(-1);
    }
    char *buf = (char *)malloc(sizeof(char) * 100);
    char *numBuf = (char *)malloc(sizeof(char) * 1);
    for (int i = 1; i <= 10; i++)
    {
        write(1, "EXAMPLE\n", strlen("EXAMPLE\n"));
    }
    int res = dup(1);
    dup2(fd,1);
    for (int i = 1; i <= 10; i++)
    {
        sprintf(numBuf, "i=%d\n", i);
        write(1, numBuf, strlen(numBuf));
    }
    dup2(res,fd);
    
    for (int i = 1; i <= 10; i++)
    {
        write(res, "Hello\n", strlen("Hello\n"));
    }

    return 0;
}
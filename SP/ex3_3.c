#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    //argv[1] = number
    //argv[2]  = name
    int number = atoi(argv[1]);
    int fd = open(argv[2], O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening");
        exit(-1);
    }
    int size = lseek(fd, 0, SEEK_END);
    char *buf = (char *)calloc(size+1, sizeof(char));
    lseek(fd, 0, SEEK_SET);
    read(fd, buf, size);
    int sz, count = 0;
    for (int i = 0; i < strlen(buf); i++)
    {
        if (count > number)
        {
            break;
        }
        if (buf[i] == '\n')
        {
            ++count;
        }
        printf("%c", buf[i]);
    }
    free(buf);
    return 0;
}
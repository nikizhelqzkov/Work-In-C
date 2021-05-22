#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    char *str;
    size_t buf = 1000;
    str = (char *)malloc(sizeof(char) * 1000);

    int fd = open(argv[1], O_CREAT | O_WRONLY|O_APPEND, 0644);
    while (1)
    {
        getline(&str, (size_t *)(&buf), stdin);
        write(fd, str, strlen(str));
    }
    close(fd);

    return 0;
}
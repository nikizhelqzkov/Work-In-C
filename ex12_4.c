#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    char *str = (char *)malloc(sizeof(char) * 100000);
    int fd;
    for (int i = 1; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd < 0)
        {
            printf(" %s : No such file or directory\n", argv[i]);
        }
        read(fd, str, 1000);
        printf("%s", str);
        close(fd);
    }

    return 0;
}
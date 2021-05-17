#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    int fd;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("%s: No such file or directory\n", argv[1]);
        exit(1);
    }
    char *buf = (char *)malloc(sizeof(char) * 10000);
    int len = read(fd, buf, 10000);
    int symbols = strlen(buf);
    int line = 0, words = 0;
    for (int i = 0; i < strlen(buf); i++)
    {
        if (buf[i] == '\n')
        {
            ++line;
        }
        if (buf[i] != ' ' && buf[i] != '\n' && buf[i] != '\t')
        {
            while (buf[i] != ' ' && buf[i] != '\n' && buf[i] != '\t' && i < strlen(buf))
            {
                ++i;
            }
            ++words;
            --i;
        }
    }

    printf(" %d %d %d %s\n", line, words, symbols, argv[1]);
    free(buf);

    return 0;
}
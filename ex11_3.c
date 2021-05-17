#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    char *str;
    size_t buf = 100;
    str = (char *)malloc(sizeof(char) * 100);

    printf("%s\n", argv[1]);
    getline(&str, (size_t *)(&buf), stdin);
     printf("%s\n", str);
    int fd;
    fd = open(argv[1], O_CREAT | O_WRONLY, 0666);
    int len;
    len = write(fd, str, strlen(str));
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '\t')
        {
            printf("Tab: %d\n", i);
            for (int j = strlen(str) - 2; j > i; j--)
            {
                str[j + 2] = str[j];
            }
            for (int k = i; k <= i + 2; k++)
            {
                str[k] = '>';
            }
        }
    }

    write(2, str, strlen(str));
    close(fd);
    return 0;
}
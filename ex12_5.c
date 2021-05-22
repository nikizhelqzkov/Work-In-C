#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    int m, n;
    char *str;
    size_t buf = 1000;
    str = (char *)malloc(sizeof(char) * 1000);
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    int fd;
    fd = open("test.txt", O_RDONLY);
    read(fd, str, 1000);
    close(fd);
    int s = 0;
    while (s < m - 1)
    {
        ++s;
    }
    while (s >= m - 1 && s < n)
    {
        printf("%c", str[s]);
        ++s;
    }

    for (int i = s; i < strlen(str); i++)
    {

        if (str[i] == '\n')
        {
            printf("\n");
            ++i;
            int count = i + m-1;
            int flag = 0;
            while (i < strlen(str) && i < count)
            {
                if (str[i] == '\n')
                {
                   
                    flag = 1;
                    break;
                }
                else
                {
                    i++;
                }
            }
            while (i < strlen(str) && flag < 1 && i < count + n-1)
            {
                if (str[i] == '\n')
                {
                    break;
                }
                else
                {
                    printf("%c", str[i]);
                    ++i;
                }
            }

            --i;
        }
    }
    printf("\n");
    return 0;
}
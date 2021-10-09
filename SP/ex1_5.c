#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countSymbols(char *buf)
{
    printf("%s", buf);
    return strlen(buf);
}
int countLines(char *buf)
{
    int lines = 1;
    for (int i = 0; i < strlen(buf); i++)
    {
        if (buf[i] == '\n')
        {
            ++lines;
        }
    }
    return lines;
}
int countWords(char *buf)
{
    int words = 0;
    for (int j = 0; j < strlen(buf); j++)
    {
        if (buf[j] != ' ' && buf[j] != '\n' && buf[j] != '\t')
        {
            while (buf[j] != ' ' && buf[j] != '\n' && buf[j] != '\t' && j < strlen(buf))
            {
                ++j;
            }
            ++words;
            --j;
        }
    }
    return words;
}
void countTogether(char **argv, int start, int argc)
{
    int fd;
    int totalC = 0, totalW = 0, totalL = 0;
    for (int i = start; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd < 0)
        {
            printf("%s: No such file or directory\n", argv[i]);
        }
        else
        {
            char *buf = (char *)malloc(sizeof(char) * 10000);
            int len;
            while ((len = read(fd, buf, 1000)) > 0)
            {
                lseek(fd, 0, SEEK_END);
            }
            int symbols = countSymbols(buf);
            int lines = countLines(buf);
            int words = countWords(buf);
            printf("File %s has:\n %d symbols \n %d words \n %d lines\n", argv[i], symbols, lines, words);
            totalC += symbols;
            totalL += lines;
            totalW += words;
            free(buf);
        }
        close(fd);
    }
    printf("Total: \n %d symbols \n %d words \n %d lines\n", totalC, totalL, totalW);
}
void readFromConsole(int isC, int isW, int isL)
{
    while (1)
    {
        char *buf = (char *)malloc(sizeof(char) * 10000);
        read(0, buf, 1000);
        if (isC > 0)
        {
            int symbols = countSymbols(buf)-1;
            printf("Your text has %d symbols\n", symbols);
        }
        if (isL > 0)
        {
            int lines = countLines(buf);
            printf("Your text has %d lines\n", lines);
        }
        if (isW > 0)
        {
            int words = countWords(buf);
            printf("Your text has %d words\n", words);
        }
        if (isC == 0 && isL == 0 && isW == 0)
        {
            printf("Error property\n");
            free(buf);
            exit(-1);
        }
    }
}
int main(int argc, char **argv)
{

    int fd, start = 1;
    int totalC = 0, totalW = 0, totalL = 0;
    if (argv[1][0] == '-')
    {
        start = 2;
        int c = 0, w = 0, l = 0;
        for (int b = 1; b < strlen(argv[1]); ++b)
        {
            if (argv[1][b] == 'c' && c == 0)
            {
                ++c;
            }
            if (argv[1][b] == 'w' && w == 0)
            {
                ++w;
            }
            if (argv[1][b] == 'l' && l == 0)
            {
                ++l;
            }
        }
        if (argc == 2)
        {
            readFromConsole(c, w, l);
        }
        else
        {
            for (int i = start; i < argc; i++)
            {
                fd = open(argv[i], O_RDONLY);
                if (fd < 0)
                {
                    printf("%s: No such file or directory\n", argv[i]);
                }
                else
                {
                    char *buf = (char *)malloc(sizeof(char) * 10000);

                    int len;
                    while ((len = read(fd, buf, 1000)) > 0)
                    {
                        lseek(fd, 0, SEEK_END);
                    }
                    if (c > 0)
                    {
                        int symbols = countSymbols(buf);
                        printf("File %s has %d symbols\n", argv[i], symbols);
                        totalC += symbols;
                    }
                    if (l > 0)
                    {
                        int lines = countLines(buf);
                        printf("File %s has %d lines\n", argv[i], lines);
                        totalL += lines;
                    }
                    if (w > 0)
                    {
                        int words = countWords(buf);
                        printf("File %s has %d words\n", argv[i], words);
                        totalW += words;
                    }
                    if (c == 0 && l == 0 && w == 0)
                    {
                        printf("Error property\n");
                        free(buf);
                        exit(-1);
                    }
                    free(buf);
                }
                close(fd);
            }
            printf("Total: ");
            if (c > 0)
            {
                printf("%d ", totalC);
            }
            if (l > 0)
            {
                printf("%d ", totalL);
            }
            if (w > 0)
            {
                printf("%d ", totalW);
            }
            printf("\n");
        }
    }
    else
    {
        countTogether(argv, 1, argc);
    }

    return 0;
}
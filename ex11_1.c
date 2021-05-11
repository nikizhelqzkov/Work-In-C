#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{

    int fd, len;
    fd = open("reader.txt", O_RDONLY);
    int sz;
    char *el = (char *)calloc(100, sizeof(char));
    int index = 0;
    sz = read(fd, &el[index], 10);
    index = strlen(el);
    while (sz > 0)
    {
        printf("%d bytes and str: %s\n", sz, el);
        sz = read(fd, &el[index], 10);
        index = strlen(el);
        printf("index: %d\n", index);
    }
    close(fd);
    el[index + 1] = '\0';
    fd = open("test.txt", O_WRONLY | O_CREAT, 0666);

    len = write(fd, el, strlen(el));
    printf("We write %d bytes\n", len);
    close(fd);
    return 0;
}
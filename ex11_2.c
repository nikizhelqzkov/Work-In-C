#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{

    int fd, len;
    fd = open("reader.txt", O_RDWR | O_CREAT, 0666);
    char *buf = "asasasasasasasasasasasfj";
    printf("%s\n", buf);
    len = write(fd, buf, strlen(buf));
    printf("bytes: %d\n", len);
    close(fd);
    fd = open("reader.txt", O_RDONLY);
    int sz;
    char *el = (char *)calloc(100, sizeof(char));
    int index = 0;
    sz = read(fd, &el[index], 10);
    index=strlen(el);
    while (sz > 0)
    {
        printf("%d bytes and str: %s\n", sz, el);
        sz = read(fd, &el[index], 10);
        index=strlen(el);
        printf("index: %d\n",index);
    }
    printf("%d bytes and str: %s\n", sz, el);
    return 0;
}
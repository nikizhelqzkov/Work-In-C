#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *el = (char *)calloc(100, sizeof(char));
    int sz;
    sz = read(fd, el, 5);
    el[sz] = '\0';
    printf("Our text is %s and bytes are: %d\n", el, sz);
    close(fd);
    fd = open("exit.txt", O_RDWR | O_CREAT,0666);
    int len;
    len = write(fd, el, strlen(el));
    printf("%d bytes are writen \n", len);
    close(fd);
    return 0;
}
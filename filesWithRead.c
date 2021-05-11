#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    printf("fd = %d\n", fd);
    char *el = (char *)calloc(100, sizeof(char));
    int sz;
    sz = read(fd, el, 5);
    el[sz] = '\0';
    printf("Our text is %s and bytes are: %d\n", el, sz);
    close(fd);
    return 0;
}
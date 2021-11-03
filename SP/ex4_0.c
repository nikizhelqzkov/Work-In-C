#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd = open("bb", O_RDONLY);
    close(0);
    int fd2 = dup(fd);
    char *buf = (char *)malloc(sizeof(char) * 100);
    char *buf2 = (char *)malloc(sizeof(char) * 100);
    read(0, buf, 2);
    read(fd2, buf2, 3);
    write(1,buf,strlen(buf));
    write(1,"\n",1);
    write(1,buf2,strlen(buf2));
    write(1,"\n",1);
    printf("%d - %d",fd,fd2);

    return 0;
}
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fdCreate = open("fff", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    close(fdCreate);
    int fd1 = open("fff", O_RDONLY);
    int fd2 = open("fff", O_WRONLY);
    int fd3 = open("fff", O_RDWR);
  
    write(fd3,"Hello",5);
    write(fd2,"worlds",6);
    char *buf1 = (char *)calloc(100, sizeof(char));
    read(fd1,buf1,6);
    write(1,buf1,6);
    close(fd2);
    write(fd3,"oops",4);
    char *buf2 = (char *)calloc(100, sizeof(char));
    read(fd1,buf2,6);
    write(1,buf2,6);

    close(fd1);
    close(fd3);
    free(buf1);
    free(buf2);
    return 0;
}
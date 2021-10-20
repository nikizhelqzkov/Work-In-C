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
    char *buf1 = "Hello World";
    write(fd2, buf1, strlen(buf1));
    char *buf2 = (char *)calloc(100, sizeof(char));
    read(fd3, buf2, 6);
    write(1, buf2, 6);
    char *buf3 = (char *)calloc(100, sizeof(char));
    read(fd1, buf3, 5);
    write(1, buf3, 6);
    char *buf4 = "chil";
    char *buf5 = "!!!";
    write(fd3, buf4, strlen(buf4));
    write(fd2, buf5, strlen(buf5));
    char *buf6 = (char *)calloc(100, sizeof(char));
    read(fd1, buf6, 9);
    write(1, buf6, 9);
    
    close(fd1);
    close(fd2);
    close(fd3);
    
    free(buf2);
    free(buf3);
   
    free(buf6);
    return 0;
}
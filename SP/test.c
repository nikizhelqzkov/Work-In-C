#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd =open("test.c",O_RDONLY);
    char c[6];
    int k = dup(0);
    int size = read(fd,c,7);
    write(1,"\n",1);
    write(1,c,size);
    
}
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(){

    int fd = open("test.t.txt",O_WRONLY|O_APPEND|O_CREAT,0666);
    if(fd < 0){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    write(1,"Hello\n",6);
    int res = dup(1);
    close(1);
    dup(fd);
    write(1,"Hey",3);
    close(1);
    dup(res);
    close(res);
    write(1,"Hallo\n",6);

    return 0;
}
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    // int f2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    int pid = fork();
    if(pid>0){
        write(fd,"hello1",6);
    }
    else{
        write(fd,"hello2",6);
    }
    return 0;
}
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
    int fd2 = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    int pid = fork();
    int status;
    if(pid==0){
        int res = dup(1);
        close(1);
        dup(fd2);
    }
    else if(pid>0){
        wait(&status); 
    }
    else{
        printf("ERRROOORR");
        exit(1);
    }
    write(1,"hello3",6);
    write(fd2,"hello4",6);
    return 0;
}
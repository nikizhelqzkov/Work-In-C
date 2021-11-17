#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("The program doesn't have 3 arguments\n");
        exit(1);
    }
    //argv[1], argv[2] --commands
    //argv[3] --> file from the dir
    int fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    char *buf = (char *)malloc(sizeof(char) * 100);
    int status;
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Error with fork");
        exit(1);
    }
    else if (pid > 0)
    {
        wait(&status);
        if (status == 0)
        {
            write(fd, argv[1], strlen(argv[1]));
        }
        execlp(argv[2], argv[2], (char *)0);
    }
    else
    {
        if (execlp(argv[1], argv[1], (char *)0) == -1)
        {
            printf("ERROR with the execution of %s\n",argv[1]);
            exit(1);
        }
    }
    return 0;
}
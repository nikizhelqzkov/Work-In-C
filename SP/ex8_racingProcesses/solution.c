#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main()
{
    char *bufP = (char *)malloc(sizeof(char) * 10);
    char *bufC = (char *)malloc(sizeof(char) * 10);
    int fd = open("raceFile.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
    {
        printf("Error with file opening!\n");
        exit(1);
    }
    int raceNum = 0;
    write(fd, "0", 1);
    lseek(fd, 0, 0);
    pid_t pid = fork();
    while (raceNum <= 1000)
    {
        if (pid > 0)
        {
            lseek(fd, 0, 0);
            read(fd, bufP, 10);
            lseek(fd, 0, 0);
            raceNum = atoi(bufP);
            raceNum++;
            sprintf(bufP, "%d", raceNum);
            lseek(fd, 0, 0);
            write(fd, bufP, strlen(bufP));
            lseek(fd, 0, 0);
            printf("\tParent: %s\n", bufP);
        }
        else if (pid == 0)
        {
            lseek(fd, 0, 0);
            read(fd, bufC, 10);
            lseek(fd, 0, 0);
            raceNum = atoi(bufC);
            raceNum += 2;
            sprintf(bufC, "%d", raceNum);
            lseek(fd, 0, 0);
            write(fd, bufC, strlen(bufC));
            lseek(fd, 0, 0);
            printf("Children: %s\n", bufC);
        }
        else
        {
            printf("Problem with pid\n");
            exit(2);
        }
    }
    return 0;
}
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main()
{
    int fd = open("raceFile.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
    {
        printf("Error with file opening!\n");
        exit(1);
    }
    int raceNum = 0;
    write(fd, &raceNum, sizeof(int));
    lseek(fd, 0, 0);
    pid_t pid = fork();
    while (raceNum <= 1000)
    {
        if (pid > 0)
        {
            lseek(fd, 0, 0);
            read(fd, &raceNum, sizeof(int));
            lseek(fd, 0, 0);
            raceNum += 1;
            lseek(fd, 0, 0);
            write(fd, &raceNum, sizeof(int));
            lseek(fd, 0, 0);
            printf("\tParent: %d\n", raceNum);
        }
        else if (pid == 0)
        {
            lseek(fd, 0, 0);
            read(fd, &raceNum, sizeof(int));
            lseek(fd, 0, 0);
            raceNum += 2;
            lseek(fd, 0, 0);
            write(fd, &raceNum, sizeof(int));
            lseek(fd, 0, 0);
            printf("Children: %d\n", raceNum);
        }
        else
        {
            printf("Problem with pid\n");
            exit(2);
        }
    }
    return 0;
}
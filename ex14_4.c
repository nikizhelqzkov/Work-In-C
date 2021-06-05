#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <wait.h>

int main(int argc, char **argv)
{
    int fd = open(argv[3], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    for (int i = 1; i < 3; i++)
    {
        int status;

        int pid = fork();
        if (pid == -1)
        {
            perror("pid");
            exit(-1);
        }
        if (pid > 0)
        {
            wait(&status);
            if (i == 1)
            {
                if (status == 0)
                {
                    write(fd, argv[i], strlen(argv[i]));
                }
                else
                {
                    perror("The command was unsuccessful\n");
                }
            }
        }
        else
        {
            exit(execlp(argv[i], argv[i], (char *)0));
        }
    }

    close(fd);
    return 0;
}
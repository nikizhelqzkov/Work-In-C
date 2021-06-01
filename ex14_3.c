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
    int success = 0, fail = 0;
    for (int i = 1; i < argc; i++)
    {
        int pid = fork();
        int status;
        if (pid == -1)
        {
            perror("pid");
            exit(-1);
        }
        else if (pid > 0)
        {
            wait(&status);
            if (status == 0)
            {

                success++;
            }
            else
            {
                fail++;
            }
        }
        else
        {
            exit(execlp(argv[i], argv[i], (char *)0));
        }
    }
    printf("Successfully commands: %d \n Faild commands: %d", success, fail);

    return 0;
}
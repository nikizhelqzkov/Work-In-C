#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    char *args[argc];
    for (int i = 1; i < argc; ++i)
    {
        args[i - 1] = argv[i];
    }
    args[argc - 1] = NULL;
    int pid = fork();
    int status = 0;
    int st = 0;
    if (pid == -1)
    {
        perror("Bad fork");
        exit(1);
    }
    else if (pid > 0)
    {
        wait(&status);
        if (status == 0)
        {
            printf("\n Successful %s\n", argv[1]);
        }
        else
        {

            printf("\nUnsuccessful %s\n", argv[1]);
        }
    }
    else
    {
        exit(execvp(argv[1], args));
    }
    return 0;
}
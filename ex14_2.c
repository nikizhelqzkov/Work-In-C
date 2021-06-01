#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

int main(int argc, char **argv)
{

    int status;
    int pid = fork();

    if (pid == 0)
    {

        int pid2 = fork();
        int status2;
        if (pid2 == 0)
        {
            exit(execlp("grep", "grep", "int", argv[1], (char *)0));
        }
        else
        {
            wait(&status2);
            char *args[argc];
            for (int i = 2; i < argc; ++i)
            {
                args[i - 2] = argv[i];
            }
            args[argc - 2] = NULL;
            exit(execvp(argv[2], args));
        }
    }
    else
    {
        wait(&status);
        printf("Status %d\n", status);
    }
    return 0;
}
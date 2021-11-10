#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

    int pid = fork();

    if (pid > 0)
    {
        int status;
        wait(&status);
        execlp("shutdown", "shutdown", "now", (char *)0);
    }
    else
    {
        execlp("sudo", "sudo", "apt", "update", (char *)0);
    }

    return 0;
}
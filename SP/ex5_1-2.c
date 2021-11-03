#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char **argv)
{

    if ((execlp("gred", "gred", "int", argv[1], (char *)0) < 0))
    {
        printf("error command");
    }

    return 0;
}
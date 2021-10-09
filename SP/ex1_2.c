#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *buf = (char *)calloc(100, sizeof(char));
    while (1)
    {
        read(0, buf, 100);
        write(1, buf, strlen(buf));
    }

    return 0;
}
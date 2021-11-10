#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <wait.h>

int main()
{

    double x = 123.4567;
    char buf[100];
    char* a;
    gcvt(x, 8, buf);

    printf("buffer is: %s\n", buf);
}
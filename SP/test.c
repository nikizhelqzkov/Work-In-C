#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    char c[6];
    int k = dup(0);
    read(k, c, 4);
    write(1, c, 1);
    read(0, c, 5);
    write(1, c, 5);
}
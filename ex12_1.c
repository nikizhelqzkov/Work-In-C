#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char *str;
    size_t buf = 1000;
    str = (char *)malloc(sizeof(char) * 1000);

    while (1)
    {
        getline(&str, (size_t *)(&buf), stdin);
        printf("%s", str);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *d;
    size_t buf = 15;
    d = (char *)malloc(sizeof(char) * (14 + 1));
    printf("Add some text: ");
    getline(&d, (size_t* )(15),stdin);
    printf("Text is: %s", d);
    return 0;
}
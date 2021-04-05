#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a = 6;

    int rev = ~a + 1;
    printf("Old element :%d and rev is: %d \n", a, rev);

    a <<= 2;
    printf("%d << 2: %d \n", (a >> 2), a);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 6995;
L:
    do
    {
        if (a >= 10 && a <= 1000)
        {
            a /= 10;
            goto L;
            
        }
        printf("Old elem: %d  new elem : %d;   ", a, (a / 10));
        a /= 10;
    } while (a >= 10);
    return 0;
}
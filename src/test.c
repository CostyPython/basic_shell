#include <stdio.h>

int main()
{
    int x = 4;

    int *pX = &x;

    int y = *pX;

    printf("%d", pX); // prints the address.
    printf("\n");
    printf("%d", y); // prints the value of x -> 4.

    return 0;
}

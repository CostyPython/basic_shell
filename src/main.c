#include <stdio.h>
void main()
{
    printf("SHELL TERMINAL> ");

    char input[100];
    fgets(input, sizeof(input), stdin);
}
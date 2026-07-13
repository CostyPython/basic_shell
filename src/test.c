#include <stdio.h>
#include <string.h>

int hash(char *str);

int main()
{
    printf("Hash: %d\n", hash("abc"));

    return 0;
}

int hash(char *str)
{
    int hash = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        hash += str[i] * (i + 1);
    }

    return hash;
}
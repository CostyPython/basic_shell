#include <stdio.h>
#include <string.h>

int newFunc(char *word);
int main()
{
    char word[1024];

    strcpy(word, "Hello World!");
    newFunc(word);

    return 0;
}

int newFunc(char *word)
{
    printf("%s", word);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef void (*Function)(void);

char userInput[1000];
char command[1000];

char commands[SIZE][32];
Function functions[SIZE] = {0};

void clear(void);
void function1(void);
void function2(void);

void addFunction(Function function, char *command);
void runCommand(char *command);

int hash(char *str);

int main()
{
    addFunction(clear, "clear");

    while (1)
    {
        printf("SHELL>");

        fgets(userInput, sizeof(userInput), stdin);

        userInput[strcspn(userInput, "\n")] = '\0';

        strcpy(command, userInput);

        runCommand(command);
    }

    return 0;
}

void runCommand(char *command)
{
    if (command[0] != '\0')
    {
        int index = hash(command);

        if (functions[index] != NULL &&
            strcmp(commands[index], command) == 0)
        {
            functions[index]();
        }
        else
        {
            printf("Unknown command: %s\n", command);
        }
    }
}

void addFunction(Function function, char *command)
{
    int index = hash(command);

    while (functions[index] != NULL)
    {
        if (strcmp(commands[index], command) == 0)
        {
            break;
        }

        index = (index + 1) % SIZE;
    }

    strcpy(commands[index], command);
    functions[index] = function;
}

int hash(char *str)
{
    unsigned int hash = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        hash += str[i] * (i + 1);
    }

    return hash % SIZE;
}

void clear(void)
{
    system("cls");
}

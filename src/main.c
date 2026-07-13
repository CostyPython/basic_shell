#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    void (*function)();
} Command;

int promptLoop(void);
char *parseInput(char *pCommand);
char *parseCommand(char *pCommand);

int hash(char *str);
Command *findCommand(char *name);

void clear();

#define TABLE_SIZE 100

Command *table[TABLE_SIZE];

int main(void)
{
    promptLoop();
    return 0;
}

int promptLoop(void)
{
    char command[1024];
    int index = 0;

    printf("\nSHELL> ");

    while (1)
    {
        if (_kbhit())
        {
            char key = _getch();

            if (key == '\r')
            {
                command[index] = '\0';

                char *hashSeed = parseInput(command);
                findCommand(hashSeed);

                index = 0;

                printf("\nSHELL> ");
            }
            else
            {
                if (index < 1023)
                {
                    printf("%c", key);

                    command[index] = key;
                    index++;
                }
                else
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

char *parseInput(char *pCommand)
{
    char *command = parseCommand(pCommand);

    return command;
}

char *parseCommand(char *pCommand)
{
    char *input = pCommand;

    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        if (input[i] == ' ')
        {
            input[i] = '\0';
            break;
        }
    }

    return input;
}

int hash(char *str)
{
    int hash = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        hash += str[i] * (i + 1);
    }

    return hash % TABLE_SIZE;
}

void clear()
{
    system("cls");
}

Command *findCommand(char *name)
{
    int index = hash(name);

    if (table[index] != NULL && strcmp(table[index]->name, name) == 0)
    {
        return table[index];
    }

    return NULL;
}
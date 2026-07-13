#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <direct.h>

#define SIZE 100

typedef void (*Function)(void);

char userInput[1000];
char command[1000];

char commands[SIZE][32];
Function functions[SIZE] = {0};

void clear(void);
void exit_shell(void);
void help(void);
void echo(void);

void add_function(Function function, char *command);
void run_command(char *command);
void parse_command(void);

int hash(char *str);

int main()
{
    add_function(clear, "clear");
    add_function(exit_shell, "exit");
    add_function(help, "help");
    add_function(echo, "echo");

    while (1)
    {
        printf("SHELL>");

        // takes and stores input
        fgets(userInput, sizeof(userInput), stdin);

        // gets rid of the enter sign at the end of the input
        userInput[strcspn(userInput, "\n")] = '\0';

        parse_command();

        run_command(command);
    }

    return 0;
}

void run_command(char *command)
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
            printf("Unknown Operation: %s\n", command);
        }
    }
}

void add_function(Function function, char *command)
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

void exit_shell(void)
{
    exit(0);
}

void help(void)
{
    printf("......................\n");
    printf("COMMANDS\n");
    printf("......................\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (functions[i] != NULL)
        {
            printf("%s\n", commands[i]);
        }
    }
}

void echo(void)
{
    int firstQuote = -1;
    int secondQuote = -1;

    for (int i = 0; userInput[i] != '\0'; i++)
    {
        if (userInput[i] == '"')
        {
            if (firstQuote == -1)
            {
                firstQuote = i;
            }
            else
            {
                secondQuote = i;
                break;
            }
        }
    }

    if (firstQuote == -1 || secondQuote == -1)
    {
        printf("Usage: echo \"text\"\n");
        return;
    }

    for (int i = firstQuote + 1; i < secondQuote; i++)
    {
        putchar(userInput[i]);
    }

    putchar('\n');
}

void parse_command(void)
{
    int i = 0;

    while (userInput[i] != ' ' && userInput[i] != '\0')
    {
        command[i] = userInput[i];
        i++;
    }

    command[i] = '\0';
}
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int print_new_line(void);
int take_user_input(void);
int parseCommand(char *pCommand);

void clear(void);

char userInput[1000];
char command[1000];

int main()
{
    print_new_line();
    take_user_input();
    parseCommand(userInput);

    return 0;
}

int print_new_line()
{
    printf("%s", "SHELL>");

    return 0;
}

int take_user_input()
{
    fgets(userInput, sizeof(userInput), stdin);
    strcpy(userInput, userInput);

    return 0;
}

int parseCommand(char *userInput)
{
    int commandIndex = 0;

    for (int i = 0; i < strlen(userInput); i++)
    {
        if (userInput[i] == ' ')
        {
            userInput[i] = '\0';
            break;
        }
    }

    strcpy(command, userInput);

    return 0;
}

void clear()
{
    system("cls");
}

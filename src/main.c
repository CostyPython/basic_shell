#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int promptLoop(void);
int parseInput(char *pCommand);
char *parseCommand(char *pCommand);

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

                parseInput(command);

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

int parseInput(char *pCommand)
{
    char *command = parseCommand(pCommand);

    printf("\nCommand: %s", command);

    return 0;
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
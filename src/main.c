#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void promptLoop(void);
void identifyCommand(char *command);

int main(void)
{
    promptLoop();
    return 0;
}

void promptLoop(void)
{

    char command[256];
    int index = 0;

    printf("\nTERMINAL> ");

    while (1)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == '\r')
            {
                identifyCommand(command);
                promptLoop();
            }
            else
            {
                printf("%c", key);
                command[index] = key;
                index++;
            }
        }
    }
}

void identifyCommand(char *command)
{

    if (strcmp(command, "clear") == 0)
    {
        system("cls");
    }
}

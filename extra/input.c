#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"

int inputAsNum()
{
    char buffer[256];
    int i = 0;
    // safely check for input
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        // convert the input to an integer number
        sscanf(buffer, "%d", &i);
    }

    return i;
}

char *safeInput(const int bufferSize)
{
    char *buffer = (char *)malloc(sizeof(char) * bufferSize);
    if (fgets(buffer, bufferSize, stdin))
    {
        // trim the string
        char *end;
        while (isspace((unsigned char)*buffer))
            buffer++;

        end = buffer + strlen(buffer) - 1;
        while (end > buffer && isspace((unsigned char)*end))
            --end;
        end[1] = '\0';

        fflush(stdin);
        return buffer;
    }
    fflush(stdin);
    return NULL;
}

void blockWithInput()
{
    fgetc(stdin);
    fflush(stdin);
}
#include "stdio.h"
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
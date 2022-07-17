#include <stdlib.h>
#include "clearscreen.h"

void clrscrn()
{
#ifdef _WIN32
    system("cls");
#elif
    system("clear");
#endif
}
#include <stdlib.h>
#include "adventure.h"

Option *newOption(char *optionText, char *get, char *need, Scene *nextScene)
{
    Option *tmp = (Option *)malloc(sizeof(Option));
    tmp->optionText = optionText;
    tmp->get = get;
    tmp->need = need;
    tmp->nextScene = nextScene;
    return tmp;
}
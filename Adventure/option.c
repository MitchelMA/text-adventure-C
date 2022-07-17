#include <stdlib.h>
#include "adventure.h"

Option *newOption(char *optionText, char *get, char *need, Scene *nextScene, Scene *(*handler)(Scene *, Option *, char **, int))
{
    Option *tmp = (Option *)malloc(sizeof(Option));
    tmp->optionText = optionText;
    tmp->get = get;
    tmp->need = need;
    tmp->nextScene = nextScene;
    tmp->handler = handler;
    return tmp;
}
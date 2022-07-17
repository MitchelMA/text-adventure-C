#ifndef ADVENTURE_HEADER
#define ADVENTURE_HEADER
#include "../Structs/Structs.h"

Scene *newScene(char *text);

Option *newOption(char *optionText, char *get, char *need, Scene *nextScene, Scene *(*handler)(Scene *, Option *));

#endif
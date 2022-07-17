#ifndef ADVENTURE_HEADER
#define ADVENTURE_HEADER
#include "..\Structs\Structs.h"
#include "..\LinkedList\linkedlist.h"

Scene *newScene(char *text);

Option *newOption(char *optionText, char *get, char *need, Scene *nextScene);

#endif
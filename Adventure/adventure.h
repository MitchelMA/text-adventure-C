#ifndef ADVENTURE_HEADER
#define ADVENTURE_HEADER
#include "../Structs/Structs.h"

Scene *newScene(char *text);
void initScene(Scene *scene);
Option *handleInput(Scene *scene, int input);

Option *newOption(char *optionText, char *get, char *need, Scene *nextScene, Scene *(*handler)(Scene *, Option *, char **, int));

Scene *basicHandler(Scene *currentScene, Option *chosenOption, char **inventory, int inventorySize);

#endif
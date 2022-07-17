#include <string.h>
#include <stdlib.h>
#include "../LinkedList/linkedlist.h"
#include "adventure.h"

Scene *newScene(char *text)
{
    Scene *tmp = (Scene *)malloc(sizeof(Scene));
    tmp->sceneText = text;
    tmp->options = newLinkedList();
    return tmp;
}
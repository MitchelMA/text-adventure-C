#include <stdio.h>
#include "Adventure/adventure.h"
#include "LinkedList\linkedlist.h"
#include "extra/bool.h"

int main(int argc, char *argv[])
{
    Scene *myScene = newScene("prachtig");
    Option *myOption = newOption("mooie optie", "", "", myScene);
    linkedListAppend(myScene->options, myOption);
    printf("adress van `myScene`: %p\n", myScene);
    printf("Text: %s\n", myScene->sceneText);
    printf("Optie 1: %s\n", myScene->options->head->value->optionText);
    printf("referentie: %p\n", myScene->options->head->value->nextScene);
    return 0;
}
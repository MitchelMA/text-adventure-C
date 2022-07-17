#include <stdio.h>
#include "Adventure/adventure.h"
#include "LinkedList\linkedlist.h"
#include "extra/bool.h"

Scene *basicHandler(Scene *currentScene, Option *chosenOption)
{
    printf("chosen option: %s", chosenOption->optionText);
    return chosenOption->nextScene;
}

int main(int argc, char *argv[])
{
    Scene *myScene = newScene("prachtig");
    Option *myOption = newOption("mooie optie", "", "", myScene, basicHandler);
    linkedListAppend(myScene->options, myOption);
    printf("adress van `myScene`: %p\n", myScene);
    printf("Text: %s\n", myScene->sceneText);
    printf("Optie 1: %s\n", myScene->options->head->value->optionText);
    printf("referentie: %p\n", myScene->options->head->value->nextScene);
    return 0;
}
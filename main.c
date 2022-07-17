#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Adventure/adventure.h"
#include "LinkedList/linkedlist.h"
#include "extra/clearscreen.h"
#include "extra/input.h"

int main(int argc, char *argv[])
{
    const int INVENTORY_LEN = 10;

    char **inventory = (char **)malloc(sizeof(char *) * INVENTORY_LEN);
    for (int i = 0; i < INVENTORY_LEN; i++)
    {
        inventory[i] = NULL;
    }

    Scene *myScene = newScene("prachtig");
    printf("Debug\n");
    Scene *sceneTwo = newScene("Tweede scene");

    Option *myOption = newOption("mooie optie", "pap", "", sceneTwo, basicHandler);
    linkedListAppend(myScene->options, myOption);

    Option *optionTwo = newOption("Mooie optie van scene 2", "", "pap", myScene, basicHandler);
    linkedListAppend(sceneTwo->options, optionTwo);
    clrscrn();
    Scene *currentScene = myScene;
    while (currentScene != NULL)
    {
        clrscrn();
        initScene(currentScene);
        int input = inputAsNum();
        Option *chosenOption = handleInput(currentScene, input);
        if (chosenOption == NULL)
        {
            printf("Dit is geen optie!");
            blockWithInput();
            continue;
        }
        currentScene = (*chosenOption->handler)(currentScene, chosenOption, inventory, INVENTORY_LEN);
    }
    return 0;
}
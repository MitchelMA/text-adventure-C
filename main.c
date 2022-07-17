#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Adventure/adventure.h"
#include "LinkedList/linkedlist.h"
#include "extra/clearscreen.h"
#include "extra/input.h"

Scene *testRem(Scene *currentScene, Option *chosenOption, char **inventory, int inventorySize)
{
    printf("voer het wachtwoord in: ");
    char *inp = safeInput(256);
    if (strcmp(inp, "1234"))
    {
        printf("Dat was het verkeerde wachtwoord");
        linkedListRemoveAt(currentScene->options, 0);
        blockWithInput();
        return currentScene;
    }

    return chosenOption->nextScene;
}

int main(int argc, char *argv[])
{
    const int INVENTORY_LEN = 10;

    char **inventory = (char **)malloc(sizeof(char *) * INVENTORY_LEN);
    for (int i = 0; i < INVENTORY_LEN; i++)
    {
        inventory[i] = NULL;
    }

    Scene *myScene = newScene("Scene 1");
    Scene *sceneTwo = newScene("Tweede scene");

    Option *myOption = newOption("Mooie optie", "pap", "", sceneTwo, basicHandler);
    linkedListAppend(myScene->options, myOption);

    Option *optionTwo = newOption("Mooie optie van scene 2", "", "pap", myScene, testRem);
    linkedListAppend(sceneTwo->options, optionTwo);

    // gameloop
    Scene *currentScene = myScene;
    while (currentScene != NULL)
    {
        clrscrn();
        initScene(currentScene);
        char *inp = safeInput(256);

        // way to check the inventory
        if (!strcmp(inp, "inventory"))
        {
            for (int i = 0; i < INVENTORY_LEN; i++)
            {
                if (inventory[i] != NULL)
                {
                    printf("%d. %s\n", i + 1, inventory[i]);
                }
            }
            blockWithInput();
            continue;
        }

        // way to exit the game
        if (!strcmp(inp, "q") || !strcmp(inp, "exit") || !strcmp(inp, "quit"))
        {
            printf("Bedankt voor het spelen!");
            break;
        }

        int inpN = 0;
        sscanf(inp, "%d", &inpN);
        Option *chosenOption = handleInput(currentScene, inpN);
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
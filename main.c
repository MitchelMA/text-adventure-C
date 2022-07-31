#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Adventure/adventure.h"
#include "LinkedList/linkedlist.h"
#include "extra/clearscreen.h"
#include "extra/input.h"
#include "Story/story.h"

Scene *testRem(Scene *currentScene, Option *chosenOption, char **inventory, int inventorySize)
{
    printf("voer het wachtwoord in: ");
    char *inp = safeInput(256);
    if (strcmp(inp, "1234"))
    {
        printf("Dat was het verkeerde wachtwoord");
        blockWithInput();
        // find the chosen option in the options
        LinkedListNode *node = currentScene->options->head;
        int index = 0;
        while (node != NULL)
        {
            printf("Test\n");
            if (node->value == chosenOption)
            {
                // match found
                Option *torm = linkedListRemoveAt(currentScene->options, index);
                if (torm != NULL)
                {
                    free(torm);
                }
                break;
            }
            index++;
            node = node->next;
        }
        return currentScene;
    }

    return chosenOption->nextScene;
}

int main(int argc, char *argv[])
{
    setupStory();
    const int INVENTORY_LEN = 10;

    char **inventory = (char **)malloc(sizeof(char *) * INVENTORY_LEN);
    for (int i = 0; i < INVENTORY_LEN; i++)
    {
        inventory[i] = NULL;
    }

    // gameloop
    Scene *currentScene = first;
    while (currentScene != NULL)
    {
        clrscrn();
        initScene(currentScene);
        char *inp = safeInput(256);

        // way to check the inventory
        if (!strcmp(inp, "inventory") || !strcmp(inp, "i"))
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

        // way to restart the game
        if (!strcmp(inp, "r") || !strcmp(inp, "restart"))
        {
            currentScene = first;
            // clear the inventory
            for (int i = 0; i < INVENTORY_LEN; i++)
            {
                if (inventory[i] != NULL)
                {
                    free(inventory[i]);
                    inventory[i] = NULL;
                }
            }
            continue;
        }

        // way to exit the game
        if (!strcmp(inp, "q") || !strcmp(inp, "e") || !strcmp(inp, "exit") || !strcmp(inp, "quit"))
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
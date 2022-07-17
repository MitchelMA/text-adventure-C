#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../LinkedList/linkedlist.h"
#include "adventure.h"
#include "../extra/input.h"

Scene *newScene(char *text)
{
    Scene *tmp = (Scene *)malloc(sizeof(Scene));
    tmp->sceneText = text;
    tmp->options = newLinkedList();
    return tmp;
}

void initScene(Scene *scene)
{
    if (scene == NULL)
    {
        return;
    }

    printf("%s\n\n", scene->sceneText);
    // print the option text
    LinkedListNode *current = scene->options->head;
    int index = 1;
    while (current != NULL)
    {
        printf("  %d. %s\n", index, current->value->optionText);

        index++;
        current = current->next;
    }
}

Option *handleInput(Scene *scene, int input)
{
    if (input < 1)
    {
        return NULL;
    }
    // get the chosen option from the linked-list as a node
    LinkedListNode *node = linkedListAt(scene->options, input - 1);

    if (node == NULL)
    {
        return NULL;
    }

    return node->value;
}

Scene *basicHandler(Scene *currentScene, Option *chosenOption, char **inventory, int inventorySize)
{
    // check for need
    if (strcmp(chosenOption->need, ""))
    {
        bool has = false;
        for (int i = 0; i < inventorySize; i++)
        {
            if (inventory[i] == NULL)
            {
                continue;
            }
            if (!strcmp(inventory[i], chosenOption->need))
            {
                has = true;
                break;
            }
        }

        if (!has)
        {
            printf("je mist een voorwerp: %s\n", chosenOption->need);
            blockWithInput();
            return currentScene;
        }
    }

    // check for get
    if (strcmp(chosenOption->get, ""))
    {
        bool has = false;
        for (int i = 0; i < inventorySize; i++)
        {
            if (inventory[i] == NULL)
            {
                continue;
            }
            if (!strcmp(inventory[i], chosenOption->get))
            {
                has = true;
                break;
            }
        }

        if (!has)
        {
            for (int i = 0; i < inventorySize; i++)
            {
                if (inventory[i] == NULL)
                {
                    inventory[i] = (char *)malloc(sizeof(char) * strlen(chosenOption->get));
                    strcpy(inventory[i], chosenOption->get);
                    printf("zojuist verkregen: %s\n", chosenOption->get);
                    blockWithInput();
                    break;
                }
            }
        }
    }
    return chosenOption->nextScene;
}
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../LinkedList/linkedlist.h"
#include "../DoubleLinkedList/doubleLinkedList.h"
#include "adventure.h"
#include "../extra/input.h"

// `Scene` implementations --------------- //
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
    if (scene == NULL || input < 1)
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

void freeScene(Scene *scene)
{
    if (scene == NULL)
    {
        return;
    }
    freeLinkedList(scene->options);
    free(scene);
}

// `Option` implementations -------------- //
Option *newOption(char *optionText, char *get, char *need, Scene *nextScene, Scene *(*handler)(Scene *, Option *, DoubleLinkedList *))
{
    Option *tmp = (Option *)malloc(sizeof(Option));
    tmp->optionText = optionText;
    tmp->get = get;
    tmp->need = need;
    tmp->nextScene = nextScene;
    tmp->handler = handler;
    return tmp;
}

// Example Handler(s) -------------------- //
Scene *basicHandler(Scene *currentScene, Option *chosenOption, DoubleLinkedList *inv)
{
    if (inv == NULL)
    {
        printf("Er is geen inventory!\n");
        return currentScene;
    }

    if (chosenOption->need != NULL && strcmp(chosenOption->need, ""))
    {
        bool has = false;
        DoubleLinkedListNode *current = inv->head;
        while (current != NULL)
        {
            const char *val = current->value;
            if (!strcmp(val, chosenOption->need))
            {
                has = true;
                break;
            }
            current = current->next;
        }

        if (!has)
        {
            printf("je mist een voorwerp: %s\n", chosenOption->need);
            blockWithInput();
            return currentScene;
        }
    }

    if (chosenOption->get != NULL && strcmp(chosenOption->get, ""))
    {
        bool has = false;
        DoubleLinkedListNode *current = inv->head;
        while (current != NULL)
        {
            const char *val = current->value;
            if (!strcmp(val, chosenOption->get))
            {
                has = true;
                break;
            }
        }

        if (!has)
        {
            size_t clen = strlen(chosenOption->get) + 1;
            char *cpy = malloc(clen);
            if (cpy == NULL)
            {
                printf("kon string niet kopiëren!\n");
                return currentScene;
            }
            strncpy(cpy, chosenOption->get, clen);
            list_append(inv, cpy);
            printf("Zojuist verkregen: %s\n", chosenOption->get);
            blockWithInput();
        }
    }
    return chosenOption->nextScene;
}
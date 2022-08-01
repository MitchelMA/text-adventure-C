#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../DoubleLinkedList/doubleLinkedList.h"
#include "adventure.h"
#include "../extra/input.h"

// LOCAL PROTOTYPES //

bool freeOptionList(DoubleLinkedList *optionList);

// END LOCAL PROTOTYPES //

// `Scene` implementations --------------- //
Scene *newScene(char *text)
{
    Scene *tmp = (Scene *)malloc(sizeof(Scene));
    tmp->sceneText = text;
    tmp->options = create_list();
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
    DoubleLinkedListNode *current = scene->options->head;
    int index = 1;
    while (current != NULL)
    {
        const Option *opt = current->value;
        printf("  %d. %s\n", index, opt->optionText);

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
    DoubleLinkedListNode *node = list_at(scene->options, input - 1);

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
    freeOptionList(scene->options);
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

bool freeOptionList(DoubleLinkedList *optionList)
{
    if (optionList == NULL)
    {
        return false;
    }

    size_t size = optionList->size;
    for (size_t i = 0; i < size; i++)
    {
        Option *torm;
        if (list_remove_at(optionList, 0, (void **)&torm))
        {
            // can now safely free the memory of `torm`
            free(torm);
        }
    }
    free(optionList);
    return true;
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
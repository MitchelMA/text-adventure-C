#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Adventure/adventure.h"
#include "extra/clearscreen.h"
#include "extra/input.h"
#include "Story/story.h"
#include "DoubleLinkedList/doubleLinkedList.h"

Scene *testRem(Scene *currentScene, Option *chosenOption, DoubleLinkedList *inv)
{
    printf("voer het wachtwoord in: ");
    char *inp = safeInput(256);
    if (strcmp(inp, "1234"))
    {
        printf("Dat was het verkeerde wachtwoord");
        blockWithInput();
        // find the chosen option in the options
        DoubleLinkedListNode *node = currentScene->options->head;
        size_t index = 0;
        while (node != NULL)
        {
            if (node->value == chosenOption)
            {
                Option *torm;
                if (list_remove_at(currentScene->options, index, (void **)&torm))
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

int main2()
{
    while (1)
    {
        Scene *myScene = newScene("Dit is een mooie scene");
        Option *opt1 = newOption("Text", NULL, NULL, myScene, basicHandler);
        list_append(myScene->options, opt1);
        freeScene(myScene);
    }
}

int main(int argc, char *argv[])
{
    setupStory();

    // inventory as double linked-list
    DoubleLinkedList *inv = create_list();

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
            DoubleLinkedListNode *current = inv->head;
            int index = 1;
            while (current != NULL)
            {
                printf("%d. %s", index, current->value);
                index++;
                current = current->next;
            }
            blockWithInput();
            continue;
        }

        // way to restart the game
        if (!strcmp(inp, "r") || !strcmp(inp, "restart"))
        {
            currentScene = first;
            size_t size = inv->size;
            // clear the inventory
            for (int i = 0; i < size; i++)
            {
                char *torm;
                if (list_remove_at(inv, 0, (void **)&torm))
                {
                    free(torm);
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
        currentScene = (*chosenOption->handler)(currentScene, chosenOption, inv);
    }
    return 0;
}
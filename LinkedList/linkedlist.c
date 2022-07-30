#include <stdlib.h>
#include "linkedlist.h"

// --- Function declarations of functions that will not be in the header file --- //
void appendEndNodeLinkage(LinkedListNode *node, Option *value);
void appendAfterNode(LinkedListNode *node, Option *value);
Option *nodeRemoveNext(LinkedListNode *node);

LinkedList *newLinkedList()
{
    LinkedList *tmp = (LinkedList *)malloc(sizeof(LinkedList));
    tmp->size = 0;
    tmp->head = NULL;
    return tmp;
}

void linkedListAppend(LinkedList *list, Option *value)
{
    if (list == NULL || value == NULL)
    {
        return;
    }
    list->size++;
    if (list->head == NULL)
    {
        LinkedListNode *tmp = (LinkedListNode *)malloc(sizeof(LinkedListNode));
        tmp->value = value;
        tmp->next = NULL;
        list->head = tmp;
        return;
    }

    appendEndNodeLinkage(list->head, value);
}

void appendEndNodeLinkage(LinkedListNode *node, Option *value)
{
    if (node == NULL || value == NULL)
    {
        return;
    }

    if (node->next == NULL)
    {
        LinkedListNode *tmp = (LinkedListNode *)malloc(sizeof(LinkedListNode));
        tmp->value = value;
        tmp->next = NULL;
        node->next = tmp;
    }
    else
    {
        appendEndNodeLinkage(node->next, value);
    }
}

void appendAfterNode(LinkedListNode *node, Option *value)
{
    if (node == NULL || value == NULL)
    {
        return;
    }

    LinkedListNode *next = node->next;
    node->next = malloc(sizeof(LinkedListNode));
    node->next->value = value;
    node->next->next = next;
}

bool linkedListInsertBefore(LinkedList *list, Option *value, unsigned long long index)
{
    if (list == NULL || value == NULL)
    {
        return false;
    }

    if (index == 0)
    {
        LinkedListNode *head = list->head;
        list->head = malloc(sizeof(LinkedListNode));
        list->head->value = value;
        list->head->next = head;
        list->size++;
        return true;
    }

    LinkedListNode *lowerbound = linkedListAt(list, index);
    LinkedListNode *upperbound = linkedListAt(list, index - 1);

    upperbound->next = malloc(sizeof(LinkedListNode));
    upperbound->next->value = value;
    upperbound->next->next = lowerbound;
    list->size++;

    return true;
}

bool linkedListInsertAfter(LinkedList *list, Option *value, unsigned long long index)
{
    if (list == NULL || value == NULL)
    {
        return false;
    }
    LinkedListNode *tmp = linkedListAt(list, index);
    if (tmp == NULL)
    {
        return false;
    }

    appendAfterNode(tmp, value);
    list->size++;
    return true;
}

LinkedListNode *linkedListAt(LinkedList *list, unsigned long long index)
{
    if (list == NULL || list->head == NULL)
    {
        return NULL;
    }

    LinkedListNode *current = list->head;
    while (index > 0)
    {
        current = current->next;
        if (current == NULL)
        {
            return NULL;
        }
        index--;
    }

    return current;
}

Option *nodeRemoveNext(LinkedListNode *node)
{
    if (node == NULL || node->next == NULL)
    {
        return NULL;
    }

    LinkedListNode *next = node->next;
    LinkedListNode *over = next->next;
    Option *option = next->value;

    free(next);
    node->next = over;
    return option;
}

Option *linkedListRemoveAt(LinkedList *list, unsigned long long index)
{
    if (list == NULL || list->head == NULL)
    {
        return NULL;
    }

    if (index == 0)
    {
        LinkedListNode *head = list->head;
        LinkedListNode *over = list->head->next;
        Option *option = head->value;
        free(head);
        list->head = over;
        list->size--;
        return option;
    }

    LinkedListNode *node = linkedListAt(list, index - 1);

    if (node == NULL)
    {
        return NULL;
    }

    Option *option = nodeRemoveNext(node);

    if (option == NULL)
    {
        return NULL;
    }

    list->size--;
    return option;
}

void freeLinkedListNodeLinkage(LinkedListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    freeLinkedListNodeLinkage(node->next);

    free(node->value);
    free(node);
}

void freeLinkedList(LinkedList *list)
{
    if (list == NULL)
    {
        return;
    }
    freeLinkedListNodeLinkage(list->head);
    free(list);
}
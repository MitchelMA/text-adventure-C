#include <stdlib.h>
#include "linkedlist.h"

LinkedList *newLinkedList()
{
    LinkedList *tmp = (LinkedList *)malloc(sizeof(LinkedList));
    tmp->size = 0;
    tmp->head = NULL;
    return tmp;
}

void linkedListAppend(LinkedList *list, int value)
{
    list->size++;
    if (list->head == NULL)
    {
        LinkedListNode *tmp = (LinkedListNode *)malloc(sizeof(LinkedListNode));
        tmp->value = value;
        tmp->next = NULL;
        list->head = tmp;
        return;
    }

    return appendAtNode(list->head, value);
}

void appendAtNode(LinkedListNode *node, int value)
{
    if (node == NULL)
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
        return appendAtNode(node->next, value);
    }
}

LinkedListNode *linkedListAt(LinkedList *list, unsigned long long index)
{
    if (list->head == NULL)
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

bool nodeRemoveNext(LinkedListNode *node)
{
    if (node->next == NULL)
    {
        return false;
    }

    LinkedListNode *over = node->next->next;
    free(node->next);
    if (over != NULL)
    {
        node->next = over;
    }
    else
    {
        node->next = NULL;
    }
    return true;
}

bool linkedListRemoveAt(LinkedList *list, unsigned long long index)
{
    if (list->head == NULL)
    {
        return false;
    }

    if (index == 0)
    {
        LinkedListNode *over = list->head->next;
        free(list->head);
        if (over != NULL)
        {
            list->head = over;
        }
        else
        {
            list->head = NULL;
        }
        list->size--;
        return true;
    }

    LinkedListNode *node = linkedListAt(list, index - 1);

    if (node == NULL)
    {
        return false;
    }

    if (nodeRemoveNext(node) == false)
    {
        return false;
    }
    list->size--;
    return true;
}
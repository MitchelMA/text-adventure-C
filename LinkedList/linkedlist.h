#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER
#include "..\extra\bool.h"

typedef struct LinkedList LinkedList;
typedef struct LinkedListNode LinkedListNode;

struct LinkedList
{
    LinkedListNode *head;
    unsigned long long size;
};

struct LinkedListNode
{
    int value;
    LinkedListNode *next;
};

LinkedList *newLinkedList();
void linkedListAppend(LinkedList *list, int value);
void appendAtNode(LinkedListNode *node, int value);
LinkedListNode *linkedListAt(LinkedList *list, unsigned long long index);
bool nodeRemoveNext(LinkedListNode *node);
bool linkedListRemoveAt(LinkedList *list, unsigned long long index);

#endif
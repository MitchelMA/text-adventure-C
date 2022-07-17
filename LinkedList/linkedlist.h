#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER
#include "../Structs/Structs.h"
#include "../extra/bool.h"

LinkedList *newLinkedList();
void linkedListAppend(LinkedList *list, Option *value);
void appendAtNode(LinkedListNode *node, Option *value);
LinkedListNode *linkedListAt(LinkedList *list, unsigned long long index);
bool nodeRemoveNext(LinkedListNode *node);
bool linkedListRemoveAt(LinkedList *list, unsigned long long index);

#endif
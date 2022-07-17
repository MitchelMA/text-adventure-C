#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER
#include "../Structs/Structs.h"
#include "../extra/bool.h"

/**
 * @brief Creates a new instance of a LinkedList Structure
 *
 * @return A new instance of a LinkedList
 */
LinkedList *newLinkedList();

/**
 * @brief Appends a new element at the end of the list
 *
 * @param list The list that will contain the new element
 * @param value The value that this element will hold
 */
void linkedListAppend(LinkedList *list, Option *value);

/**
 * @brief Recursively tries to append a new LinkedListNode after this node
 *
 * @param node
 * @param value
 */
void appendAtNode(LinkedListNode *node, Option *value);

/**
 * @brief Gets the LinkedListNode at the specified index
 *
 * @param list
 * @param index
 * @return LinkedListNode*
 */
LinkedListNode *linkedListAt(LinkedList *list, unsigned long long index);

/**
 * @brief Removes the succesive node and fills the gap with the one that comes after the removed node
 *
 * @param node The node whose succesive node will get removed
 * @return A boolean determining if the node was removed or not
 */
bool nodeRemoveNext(LinkedListNode *node);

/**
 * @brief Removes the LinkedListNode at the specified index
 *
 * @param list The list whose Node will get removed
 * @param index The index at which it will try to remove the node from
 * @return A boolean determining if the node was removed or not
 */
bool linkedListRemoveAt(LinkedList *list, unsigned long long index);

#endif
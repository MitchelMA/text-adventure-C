#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__
#include "../Structs/Structs.h"

/**
 * @brief Create a double link-list object.
 *
 * @return DoubleLinkedList*
 */
DoubleLinkedList *create_list();

/**
 * @brief Appends a new item at the end of the double linked-list.
 *
 * @param list
 * @param value
 * @return 1 when the append was succesful, else 0
 */
int list_append(DoubleLinkedList *list, void *value);

/**
 * @brief Returns the `DoubleLinkedListNode` from the list at a specified index.
 *
 * @param list
 * @param index
 * @return DoubleLinkedListNode* at the specified index
 */
DoubleLinkedListNode *list_at(DoubleLinkedList *list, unsigned long long index);

/**
 * @brief Remove an item from the list at a specified index.
 * If it returns 1, then it was succesfully removed, else 0.
 *
 * @param list
 * @param index
 * @param out A pointer that points to the address that the value previously held by the node lives at.
 * This way you can manually free this memory address
 * @return 1 when removing was sucessful, else 0
 */
int list_remove_at(DoubleLinkedList *list, unsigned long long index, void **out);

/**
 * @brief Inserts a new item into the list before the node at the specified index.
 *
 * @param list
 * @param value
 * @param index
 * @return 1 when inserting was succesful, else 0.
 */
int list_insert_before(DoubleLinkedList *list, void *value, unsigned long long index);

/**
 * @brief Inserts a new item into the list after the node at the specified index.
 *
 * @param list
 * @param value
 * @param index
 * @return 1 when inserting was succesful, else 0.
 */
int list_insert_after(DoubleLinkedList *list, void *value, unsigned long long index);

#endif // __DOUBLE_LINKED_LIST_H__
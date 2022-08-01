#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__
#include "../Structs/Structs.h"

DoubleLinkedList *create_list();
int list_append(DoubleLinkedList *list, void *value);
DoubleLinkedListNode *list_at(DoubleLinkedList *list, unsigned long long index);
int list_remove_at(DoubleLinkedList *list, unsigned long long index, void **out);
int list_insert_before(DoubleLinkedList *list, void *value, unsigned long long index);
int list_insert_after(DoubleLinkedList *list, void *value, unsigned long long index);

#endif // __DOUBLE_LINKED_LIST_H__
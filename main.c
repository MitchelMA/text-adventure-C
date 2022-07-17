#include <stdio.h>
#include "LinkedList/linkedlist.h"
#include "extra/bool.h"

int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    LinkedList *myList = newLinkedList();
    linkedListAppend(myList, 10);
    linkedListAppend(myList, 20);
    linkedListAppend(myList, 30);
    int removeIndex = 3;
    bool succesfulRemoved = linkedListRemoveAt(myList, removeIndex);
    printf("succesfully removed index %d: %s\n", removeIndex, succesfulRemoved ? "true" : "false");
    printf("size: %I64d\n", myList->size);
    printf("first value: %d\n", linkedListAt(myList, 0)->value);
    printf("second value: %d\n", linkedListAt(myList, 1)->value);
    printf("third value: %d\n", linkedListAt(myList, 2)->value);

    return 0;
}
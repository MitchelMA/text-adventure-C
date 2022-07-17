#ifndef STRUCTS_HEADER
#define STRUCTS_HEADER

#pragma region ADVENTURE

/**
 * @brief Structure that contains all the info about a scene
 *
 */
typedef struct Scene Scene;

/**
 * @brief Structure that contains all the info about an option in a scene
 *
 */
typedef struct Option Option;

#pragma endregion ADVENTURE

#pragma region LINKDEDLIST

/**
 * @brief Structure that contians the head and size. @n
 * A linked list can increase and decrease in size at will.
 *
 */
typedef struct LinkedList LinkedList;

/**
 * @brief Structure that is part of a LinkedList. @n
 * A LinkedListNode contains (in this situation) an Option for a Scene and @n
 * a reference to the next element in the list.
 *
 */
typedef struct LinkedListNode LinkedListNode;

#pragma endregion LINKEDLIST

#pragma region STRUCTSETUP

struct Scene
{
    char *sceneText;
    LinkedList *options;
};

struct Option
{
    char *optionText;
    char *get;
    char *need;
    Scene *nextScene;
    Scene *(*handler)(Scene *, Option *, char **, int);
};

struct LinkedList
{
    LinkedListNode *head;
    unsigned long long size;
};

struct LinkedListNode
{
    Option *value;
    LinkedListNode *next;
};

#pragma endregion STRUCTSETUP

#endif
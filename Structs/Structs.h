#ifndef STRUCTS_HEADER
#define STRUCTS_HEADER

#pragma region ADVENTURE

typedef struct Scene Scene;
typedef struct Option Option;

#pragma endregion ADVENTURE

#pragma region LINKDEDLIST

typedef struct LinkedList LinkedList;
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
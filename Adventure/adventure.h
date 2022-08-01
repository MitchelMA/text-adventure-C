#ifndef ADVENTURE_HEADER
#define ADVENTURE_HEADER
#include "../Structs/Structs.h"
#include "../extra/bool.h"

/**
 * @brief Creates a new instance of a Scene structure
 *
 * @param text The text that will be displayed when the Scene is initialized
 * @return The new instance of a Scene Structure
 */
Scene *newScene(char *text);

/**
 * @brief outputs the text and the options of the scene
 *
 * @param scene The scene whose text and options will be displayed
 */
void initScene(Scene *scene);

/**
 * @brief Handles the input of the player correctly (e.g. checking for NULL values)
 *
 * @param scene The scene whose Options will be checked
 * @param input The input value as a number
 * @return The chosen option by the user
 */
Option *handleInput(Scene *scene, int input);

/**
 * @brief Frees the memory of a Scene
 *
 * @param scene A pointer of type `Scene` at which the memory gets cleared
 */
void freeScene(Scene *scene);

/**
 * @brief Creates a new instance of an Option Structure
 *
 * @param optionText The text that will be displayed when the scene that contains this option is initialized
 * @param get The item that the player will get in their inventory by choosing this option
 * @param need The item that the player will need to be able to choose this option
 * @param nextScene A reference to the next scene
 * @param handler A Function Pointer that will handle the input of the player
 * @return The new instance of an Option Structure
 */
Option *newOption(char *optionText, char *get, char *need, Scene *nextScene, Scene *(*handler)(Scene *, Option *, DoubleLinkedList *));

/**
 * @brief The basic option-handle function
 *
 * @param currentScene A reference to the current scene
 * @param chosenOption A reference to the chosen option
 * @param inventory The inventory of the player
 * @param inventorySize The size of the inventory of the player
 * @return The reference to the next scene
 */
Scene *basicHandler(Scene *currentScene, Option *chosenOption, DoubleLinkedList *inv);

#endif
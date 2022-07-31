#include "story.h"
#include <stdlib.h>

void setupStory()
{
    first = newScene("Scene 1");
    Option *option = newOption("Option 1", NULL, NULL, first, basicHandler);
    linkedListAppend(first->options, option);
}
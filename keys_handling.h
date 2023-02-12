#ifndef KEYS_HANDLING_H_INCLUDED
#define KEYS_HANDLING_H_INCLUDED

#include "CApp.h"

class Keys_Handling
{
public:
    Keys_Handling();

    static void key_up(SDL_KeyboardEvent* event, unsigned int* pos_x, unsigned int* pos_y);
    static void key_down(SDL_KeyboardEvent* event, unsigned int* pos_x, unsigned int* pos_y);
};


#endif // KEYS_HANDLING_H_INCLUDED

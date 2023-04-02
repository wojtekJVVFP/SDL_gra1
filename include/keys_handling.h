#ifndef KEYS_HANDLING_H_INCLUDED
#define KEYS_HANDLING_H_INCLUDED

#include "CApp.h"

class Keys_Handling
{
private:

public:
    int up;
    int down;
    int left;
    int right;
    int step;
    Keys_Handling(int u=0, int d=0, int l=0, int r=0);

    void key_up(SDL_KeyboardEvent* event);
    void key_down(SDL_KeyboardEvent* event, class Player* p, class Map* m, class Npc* n);
};


#endif // KEYS_HANDLING_H_INCLUDED

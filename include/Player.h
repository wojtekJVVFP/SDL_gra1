#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"


class Player: public Entity //dziedziczenie publiczne po klasie Entity
{
    public:
        Player(int x=200, int y=200);
        ~Player();

        friend class Keys_Handling;
        friend class CApp;
        friend class CSurface;

    protected:

    private:


};

#endif // PLAYER_H

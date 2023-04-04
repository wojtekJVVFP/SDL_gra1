#ifndef NPC_H
#define NPC_H

#include "Entity.h"

class Npc: public Entity
{
    public:
        Npc(int x=100, int y=100);
        ~Npc();
        void wander(class Map* m, class Player* p);
        void move_entity(int x, int y);

        friend class CApp;
        friend class Keys_Handling;


    protected:

    private:
};

#endif // NPC_H

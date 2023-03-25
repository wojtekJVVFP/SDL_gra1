#ifndef NPC_H
#define NPC_H

#include "Entity.h"

class Npc: public Entity
{
    public:
        Npc(int x=0, int y=0);
        ~Npc();

        friend class CApp;


    protected:

    private:
};

#endif // NPC_H

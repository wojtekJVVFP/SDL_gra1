#include "CApp.h"
#include "Npc.h"


Npc::Npc(int x, int y)
: Entity(x,y)
{
    //ctor

}

Npc::~Npc()
{
    //dtor
    SDL_DestroyTexture(texture);
}

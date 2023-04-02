#include "CApp.h"
#include "Npc.h"
#include "Map.h"


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


/*
movement of npces
run inside time controlled loop
*/
void Npc::wander(class Map* m)
{
    SDL_Rect temp = player_rect;
    static int dir = 1;

    temp.x = get_x() + dir;
    temp.y = get_y() + dir;

    if(!m->collide_rect(temp).ret_bool)
    {
        move_entity(dir, dir);
    }
    else
    {
        dir *= -1;
    }


}

void Npc::move_entity(int x, int y)
{
    pos_x = get_x() + x;
    pos_y = get_y() + y;

    //updating player_rect of npc
    player_rect.x = pos_x;
    player_rect.y = pos_y;
}

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
}


/*
movement of npces
run inside time controlled loop
*/
void Npc::wander(class Map* m, class Player* p)
{
    SDL_Rect temp = player_rect;
    static int dx = 1;
    static int dy = 1;

    Int_bool ret;

    temp.x = get_x() + dx;
    temp.y = get_y() + dy;  //creating rect to check collision

    ret = m->collide_rect(temp);    //checking collision with map objects
    if((!ret.ret_bool) && (!p->collide_rect(temp)) )
    {
        move_entity(dx, dy);
        calc_traj(dx, dy);
    }
    else    //collision detected
    {
        calc_collision(m, ret.ret_int);
        dx *= -1;
        dy *= -1;
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

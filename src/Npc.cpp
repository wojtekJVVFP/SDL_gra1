#include <iostream>
#include <array>
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

    static int rep = 0;
    static int it = 45;

    static Increments inc = ang_to_inc(it);

    /*rep = (++rep)%100;
    if(rep == 99)
    {
       it += 60;
    }

    if(it == 360)it = 0;
    */
    double dx = inc.dx;
    double dy = inc.dy;

    Int_bool ret;

    temp.x = get_x() + dx;
    temp.y = get_y() + dy;  //creating rect to check collision

    ret = m->collide_rect(temp);    //checking collision with map objects
    if((!ret.ret_bool) && (!p->collide_rect(temp)) )//no collision
    {
        move_entity(dx, dy);
        calc_traj(dx, dy);
    }
    else    //collision detected
    {
        inc = calc_collision(m, ret.ret_int, inc);
    }
}

void Npc::move_entity(double x, double y)
{
    pos_x = get_x() + x;
    pos_y = get_y() + y;

    //updating player_rect of npc
    player_rect.x = pos_x;
    player_rect.y = pos_y;
}

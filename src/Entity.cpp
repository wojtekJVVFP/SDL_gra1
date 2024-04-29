#include <iostream>
#include <array>
#include <algorithm>
#include "CApp.h"
#include "Entity.h"
#include "color_definition.h"


using namespace std;

Entity::Entity(int x, int y)
{
    //ctor
    pos_x = x;
    pos_y = y;
    texture = NULL;
    player_width = 0;
    player_height = 0;
    SDL_Rect player_rect;
}

Entity::~Entity()
{
    //dtor
    SDL_DestroyTexture(texture);
}

Entity::Entity(const Entity& other)
{
    //copy ctor
}

double Entity::get_x()
{
   return pos_x;
}


double Entity::get_y()
{
  return pos_y;
}

bool Entity::load_texture(const char* filename, SDL_Renderer* render)
{
    SDL_Surface* Surf_Temp = NULL;

    if( (Surf_Temp = SDL_LoadBMP(filename) ) == NULL)
    {
        cout<<"błąd";
        return false;
    }

    player_height = Surf_Temp->h;
    player_width = Surf_Temp->w;
    player_rect = Surf_Temp->clip_rect;


    if((texture = SDL_CreateTextureFromSurface(render, Surf_Temp)) == NULL)
    {
        cout<<"błąd";
        return false;
    }
    //Uint8 a=255;
    //SDL_SetTextureAlphaMod(player_texture,a);


    //initialising player dimension
    //player_height = SDL_Get

    SDL_FreeSurface(Surf_Temp);

    return true;

}

void Entity::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, WHITE, 255);
    player_rect.x = (int) pos_x;
    player_rect.y = (int) pos_y;

    SDL_RenderCopy(renderer, texture, NULL, &player_rect);
}

/*
Funkcja sprawdza czy podany rect koliduje z mapą i zwraca true jeśli tak

*/
bool Entity::collide_rect(SDL_Rect r)
{
    SDL_Rect m = player_rect;

    bool x_collides = false;
    bool y_collides = false;

    if( (r.x+r.w < m.x+m.w) && (r.x+r.w > m.x) )//kolizja z prawej na x gracz=>obiekt
    {
        #if COLLIDE_TEST == 1
        cout<<"kolizja x1"<<endl;
        #endif
        x_collides = true;
    }
    else if( (r.x > m.x) && (r.x < m.x+m.w) )//kolizja z lewej na x obiekt<=gracz
    {
        #if COLLIDE_TEST == 1
        cout<<"kolizja x2"<<endl;
        #endif
        x_collides = true;
    }
    else if( (r.x < m.x) && (r.x+r.w > m.x+m.w) )//kolizja z lewej na x obiekt<=gracz
    {
        #if COLLIDE_TEST == 1
        cout<<"kolizja x3"<<endl;
        #endif
        x_collides = true;
    }

    if( (r.y < m.y+m.h) && (r.y > m.y) )//gracz na dole idzie do góry, kolizja na y
    {
        #if COLLIDE_TEST == 1
        cout<<"kolizja y1"<<endl;
        #endif
        y_collides = true;
    }
    else if( (r.y+r.h < m.y+m.h) && (r.y+r.h > m.y) )//gracz na górze idzie do dołu, kolizja y
    {
        #if COLLIDE_TEST == 1
        cout<<"kolizja y2"<<endl;
        #endif
        y_collides = true;
    }
    else if( (r.y < m.y) && (r.y+r.h > m.y+m.h) )//kolizja gracza mniejszego od obiektu, który dotyka od środka
    {
        #if COLLIDE_TEST == 1
        cout<<"kolizja y3"<<endl;
        #endif
        y_collides = true;
    }

    if(x_collides && y_collides)
    {
        return true;
    }
    return false;
}


/*
P1 = (pos_x, pos_y)
P2 = (pos_x+dx, pos_y+dy)

*/
void Entity::calc_traj(double dx, double dy)
{

    if((dx > 0.000001) || (dx < -0.000001))   //if dividing by non zero value, in double
    {
        a = dy / dx;
    }
    else
    {
        a = 1000;   //let's assume this as straight vertical line
    }
    b = pos_y - a * pos_x;
}


/*
calc_collision
- calculates which map objects collide with entity using straight line of entity trajectory and object straight lines
- calculating common point of straights and checking if this point belong to object

inputs:
-

uses a[4] and b[4] and points[4] from map.h
uses a,b and

return new increments value
*/
Increments Entity::calc_collision(class Map* m, int object_no, Increments dxdy)
{
    int xp, yp;
    array<int,4> distances;   //distances from 4 object lines


    for(int i=0; i < 4; i++)
    {

        xp = (int)((b-(m->map_rects[object_no].b[i]))/(m->map_rects[object_no].a[i]-a)); //calculating common point x and y
        yp = (int)(a*xp+b);

        p_col[i] = {xp, yp};
        distances[i] = points_distance(xp, yp, pos_x, pos_y);


        cout<<i<<": "<<"Punkt policzony: "<<xp<<" "<<yp<<" Odl od linii: "<<distances[i]<<"\n";//checking if point belongs to the line
        cout<<"xp, yp:"<<xp<<","<<yp<<", "<<"pos_x,pos_y:"<<pos_x<<","<<pos_y<<"\n";
        //narysować punkty obliczone na mapie
    }
    //skąd wiedzieć, która prosta jest najbliżej?

    int nr_prostej = (int) (std::min_element(distances.begin(), distances.end()) - distances.begin());
    cout<<"kolizja z prosta nr: "<<nr_prostej<<"\n";

    //z którą prostą nastąpiło zderzenie?
    // b = m->map_rects[object_no].b[i]
    // a = m->map_rects[object_no].a[i]

    //przeliczyć kąt uderzenia w odniesienieniu do ox - kąt gamma
    double gamma = inc_to_ang(dxdy);
    double omega = 180 - 2*gamma;
    Increments out = ang_to_inc(omega);

        //cout<<"5 st na rad: "<<ang_to_inc(5).dx<<", "<<ang_to_inc(5).dy<<"\n";
    return out;
}

void Entity::draw_traj(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, BLACK, 255);
    int x1, y1, x2, y2;

    x1 = pos_x - 100;
    y1 = (int) (a*x1 + b);

    x2 = pos_x + 100;
    y2 = (int) (a*x2 + b);


    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_SetRenderDrawColor(renderer, RED, 255);
    SDL_RenderDrawPoints(renderer, p_col, 4);
}


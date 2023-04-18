#include <iostream>
#include "CApp.h"
#include "Entity.h"
#include "color_definition.h"
#include "geometry.h"

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

int Entity::get_x()
{
   return pos_x;
}


int Entity::get_y()
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
    player_rect.x = pos_x;
    player_rect.y = pos_y;

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
void Entity::calc_traj(int dx, int dy)
{
    if(dx!=0)   //if dividing by non zero value
    {
        a = (float) dy / dx;
    }
    else
    {
        a = 1000;   //let's assume this as straight vertical line
    }
    b = (float) pos_y - a * (float)pos_x;
}


/*
calc_collision
- calculates which map objects collide with entity using straight line of entity trajectory and object straight lines
- calculating common point of straights and checking if this point belong to object

inputs:
-

uses a[4] and b[4] and points[4] from map.h
uses a,b and
*/
void Entity::calc_collision(class Map* m, int object_no)
{
    int xp, yp;
    int distances[4];   //distances from 4 object lines

    for(int i=0; i < 4; i++)
    {
        xp = (int)((b-(m->map_rects[object_no].b[i]))/(m->map_rects[object_no].a[i]-a)); //calculating common point x and y
        yp = (int)(a*xp+b);

        cout<<"Punkt policzony: "<<xp<<" "<<yp<<"Odl od linii: "<<points_distance(xp, yp, pos_x, pos_y)<<endl;//checking if point belongs to the line
    }
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
}


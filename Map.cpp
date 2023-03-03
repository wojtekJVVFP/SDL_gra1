#include <iostream>
#include "CApp.h"
#include "Map.h"
#include "color_definition.h"

using namespace std;

Map::Map()
{//ctor
    map_rects[0] = {100,300,70,70};

}

Map::~Map()
{
    //dtor
}


/*
Jak utworzyć nową teksturę i narysować na niej linie i prostokąty?

*/

void Map::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, BLACK, 255);
    SDL_RenderDrawLine(renderer, 100, 200, 300, 200);

    SDL_Rect DestR = {500, 300, 100, 200};
    SDL_RenderDrawRect(renderer, &DestR);

    SDL_RenderDrawRect(renderer, &map_rects[0]);
}



/*Napisać funkcję, która sprawdza czy gracz będąc w danej pozycji koliduje z obiektem z mapy
Wywołanie w miejscu, gdzie zmieniana jest pozycja

zwraca true, gdy podany rect koliduje z mapą

-problem z działaniem kolizji, gdy gracz zbliża się od dołu - funkcja nie wykrywa wejścia na kilka-kilkanaście pikseli

*/
bool Map::player_collides(SDL_Rect r)
{
    SDL_Rect m = map_rects[0];
    bool x_collides = false;
    bool y_collides = false;

    if( (r.x+r.w < m.x+m.w) && (r.x+r.w > m.x) )//kolizja z prawej na x gracz=>obiekt
    {
        cout<<"kolizja x1"<<endl;
        x_collides = true;
    }
    else if( (r.x > m.x) && (r.x < m.x+m.w) )//kolizja z lewej na x obiekt<=gracz
    {
        cout<<"kolizja x2"<<endl;
        x_collides = true;
    }

    if( (r.y > m.y-m.h) && (r.y < m.y) )//gracz na dole idzie do góry, kolizja na y
    {
        cout<<"kolizja y1"<<endl;
        y_collides = true;
    }
    else if( (r.y-r.h > m.y-m.h) && (r.y-r.h < m.y) )//gracz na górze idzie do dołu, kolizja y
    {
        cout<<"kolizja y2"<<endl;
        y_collides = true;
    }

    if(x_collides && y_collides)
    {
        return true;
    }
    else
    {
        return false;
    }

}

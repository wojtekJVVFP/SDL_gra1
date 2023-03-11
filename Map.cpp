#include <iostream>
#include "CApp.h"
#include "Map.h"
#include "color_definition.h"

using namespace std;

/*
Jak dynamicznie dodawać obiekty do mapy i liczyć ile ich jest?

*/



Map::Map()
{//ctor
    //map_rects[0] = {100,300,350,200};
    //map_rects[1] = {500, 300, 100, 200};
//    map_rects[2] = {470, 600, 50, 100};

    object_count = 1;
    map_rects = new SDL_Rect[object_count];
    map_rects[0] = {100,300,350,200};

}
Map::~Map()
{
    delete[] map_rects;//dtor
}

/*
Funkcja do dodawania jednego obiektu na końcu listy map_rects

obj_count = 1;
*/
void Map::add_map_object(int obj_id, SDL_Rect obj_rect)
{
    //tworzenie nowej tablicy
    SDL_Rect* temp_obj = new SDL_Rect[object_count+1];

    //przepisywanie danych z map_rects do temp_obj
    for(int i=0; i<object_count; i++)
    {
       temp_obj[i] = map_rects[i];
    }
    temp_obj[object_count] = {obj_rect.x, obj_rect.y, obj_rect.w, obj_rect.h};

    delete[] map_rects;
    map_rects = temp_obj;

    object_count++;
}





/*
Jak utworzyć nową teksturę i narysować na niej linie i prostokąty?

*/

void Map::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, BLACK, 255);
    SDL_RenderDrawLine(renderer, 100, 200, 300, 200);

    for(int i=0; i<object_count; i++)
    {
        SDL_RenderDrawRect(renderer, &map_rects[i]);
    }

    //cout<<"Rozmiar obiektu: "<<sizeof(SDL_Rect)<<endl;
}



/*Napisać funkcję, która sprawdza czy gracz będąc w danej pozycji koliduje z obiektem z mapy
Wywołanie w miejscu, gdzie zmieniana jest pozycja

zwraca true, gdy podany rect koliduje z mapą


*/
bool Map::player_collides(SDL_Rect r)
{
    for(int i=0; i<object_count; i++)
    {
        SDL_Rect m = map_rects[i];

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

        if( (r.y < m.y+m.h) && (r.y > m.y) )//gracz na dole idzie do góry, kolizja na y
        {
            cout<<"kolizja y1"<<endl;
            y_collides = true;
        }
        else if( (r.y+r.h < m.y+m.h) && (r.y+r.h > m.y) )//gracz na górze idzie do dołu, kolizja y
        {
            cout<<"kolizja y2"<<endl;
            y_collides = true;
        }

        if(x_collides && y_collides)
        {
            return true;
        }
    }
    return false;
}

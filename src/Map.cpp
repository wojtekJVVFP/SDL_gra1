#include <iostream>
#include "CApp.h"
#include "Map.h"
#include "color_definition.h"

using namespace std;


Map::Map()
{//ctor
    const int map_width = 1000;
    const int map_height = 500;
    const int border_width = 30;

    #define test 1
    #if test == 1
    object_count = 4;
    map_rects = new Object[object_count];
    map_rects[0].rect = {border_width,0,map_width,border_width};   //bloki graniczne
    map_rects[0].id = 2;
    map_rects[1].rect = {0,0, border_width, map_height+2*border_width};
    map_rects[1].id = 2;
    map_rects[2].rect = {border_width, map_height+border_width, map_width, border_width};
    map_rects[2].id = 2;
    map_rects[3].rect = {map_width+border_width, 0, border_width, map_height+2*border_width};
    map_rects[3].id = 2;
    #else
    object_count = 1;
    #endif



}
Map::~Map()
{//dtor
    delete[] map_rects;//dtor
}

/*
Funkcja do dodawania jednego obiektu na końcu listy map_rects
WE: - obj_id,
    - obj_rect - prostokąt do dodania
obj_count = 1;
*/
void Map::add_map_object(int obj_id, SDL_Rect obj_rect)
{
    //tworzenie nowej tablicy
    Object* temp_obj = new Object[object_count+1];
    //Object* temp2_obj = new Object[object_count+1];

    //przepisywanie danych z map_rects do temp_obj
    for(int i=0; i<object_count; i++)
    {
       temp_obj[i] = map_rects[i];
    }
    temp_obj[object_count].rect = obj_rect;//{obj_rect.x, obj_rect.y, obj_rect.w, obj_rect.h};
    temp_obj[object_count].id = obj_id;

    delete[] map_rects;
    map_rects = temp_obj;   //temp_obj nie będzie tu kasowane, bo pamięć zostanie zwolniona w destruktorze klasy

    object_count++;
}


/*
funkcja do usuwania z mapy jednego obiektu o numerze obj_no


*/
void Map::delete_map_object(int obj_no)
{
    //tworzenie nowej tablicy
    Object* temp_obj = new Object[object_count-1];

    //przepisywanie danych z map_rects do temp_obj z pominięciem obiektu o numerze obj_no
    for(int i=0; i<obj_no; i++)
    {
       temp_obj[i] = map_rects[i];
    }
    for(int i=obj_no+1; i<object_count; i++)
    {
       temp_obj[i-1] = map_rects[i];
    }

    delete[] map_rects;
    map_rects = temp_obj;

    object_count--;
}

void Map::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, BLACK, 255);
    //SDL_RenderDrawLine(renderer, 100, 200, 300, 200);

    for(int i=0; i<object_count; i++)
    {
        SDL_RenderDrawRect(renderer, &map_rects[i].rect);
        switch(map_rects[i].id)
        {
        case 0:
            break;
        case 1:
            SDL_RenderCopy(renderer, stone_texture, NULL, &map_rects[i].rect);
            break;
        default:
            break;
        }
    }

    //cout<<"Rozmiar obiektu: "<<sizeof(SDL_Rect)<<endl;
}

/*Napisać funkcję, która sprawdza czy gracz będąc w danej pozycji koliduje z obiektem z mapy
Wywołanie w miejscu, gdzie zmieniana jest pozycja

zwraca true, gdy podany rect koliduje z mapą

-trzeba dodać kolejny warunek, który sprawdza kolizję z obiektem mniejszym niż gracz
*/
Int_bool Map::collide_rect(SDL_Rect r)
{
    Int_bool ret;

    for(int i=0; i<object_count; i++)
    {
        SDL_Rect m = map_rects[i].rect;

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
        else if( (r.x < m.x) && (r.x+r.w > m.x+m.w) )//kolizja z lewej na x obiekt<=gracz
        {
            cout<<"kolizja x3"<<endl;
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
        else if( (r.y < m.y) && (r.y+r.h > m.y+m.h) )//kolizja gracza mniejszego od obiektu, który dotyka od środka
        {
            cout<<"kolizja y3"<<endl;
            y_collides = true;
        }

        if(x_collides && y_collides)
        {
            ret.ret_bool = true;
            ret.ret_int = i;
            return ret;
        }
    }
    ret.ret_bool = false;
    ret.ret_int = 0;

    return ret;
}

bool Map::load_object_textures(SDL_Renderer* render)
{
    SDL_Surface* Surf_Temp = NULL;
    const char* filename = "bmp/stone.bmp";

    if( (Surf_Temp = SDL_LoadBMP(filename) ) == NULL)
    {
        cout<<"błąd";
        return false;
    }

    //player_height = Surf_Temp->h;
    //player_width = Surf_Temp->w;
   // player_rect = Surf_Temp->clip_rect;


    if((stone_texture = SDL_CreateTextureFromSurface(render, Surf_Temp)) == NULL)
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

/*
    move_camera - moves all the objects inside map_rects by x and y dimensions
*/
void Map::move_camera(int x, int y)
{
   for(int i=0; i<object_count; i++)
   {
       map_rects[i].rect.x += x;
       map_rects[i].rect.y += y;
   }
}

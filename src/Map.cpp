#include <iostream>
#include "CApp.h"
#include "Map.h"
#include "color_definition.h"

using namespace std;


/**< Point class */
Object::Object()
{
    rect = {0, 0, 10, 10};  //init values
    id = 0;
    destroyable = true;
}
Object::~Object()
{
    //dtor
}
void Object::calc_points()
{
    int dx,dy;

    points[0] = {rect.x, rect.y+rect.h};
    points[1] = {rect.x+rect.w, rect.y+rect.h};
    points[2] = {rect.x+rect.w, rect.y};
    points[3] = {rect.x, rect.y};

    for(int i=0; i<3; i++)
    {
        if((points[i+1].x - points[i].x) != 0)   //if dividing by non zero value
        {
            a[i] = (float)(points[i+1].y - points[i].y )/ (points[i+1].x - points[i].x);
        }
        else
        {
            a[i] = 1000;   //let's assume this as straight vertical line
        }
        b[i] = (float) points[i].y - a[i] * (float)points[i].x;
    }

    if((points[0].x - points[3].x) != 0)   //if dividing by non zero value
    {
        a[3] = (float)(points[0].y - points[3].y )/ (points[0].x - points[3].x);
    }
    else
    {
        a[3] = 1000;   //let's assume this as straight vertical line
    }
    b[3] = (float) points[3].y - a[3] * (float)points[3].x;
}
bool Object::getDestroyable()
{
    return destroyable;
}

void Object::setDestroyable(bool a)
{
    destroyable = a;
}

SDL_Rect Object::getRect()
{
    return rect;
}
void Object::setRect(SDL_Rect a)
{
    rect = a;
}
void Object::setId(int a)
{
    id = a;
}
int Object::getId()
{
    return id;
}

Map::Map()
{//ctor
    const int map_width = 1000;
    const int map_height = 500;
    const int border_width = 30;

    #define test 1
    #if test == 1

    SDL_Rect temp;
    object_count = 1;
    //map_rects = new Object[object_count];   //jest to już zbiornikiem na obiekty
    map_rects.push_back(Object());

    map_rects[0].setRect({0,0,2,2});
    map_rects[0].setId(0);

    temp = {border_width,0,map_width,border_width};
    add_map_object(2, temp);

    temp = {0,0, border_width, map_height+2*border_width};
    add_map_object(2, temp);

    temp = {border_width, map_height+border_width, map_width, border_width};
    add_map_object(2, temp);

    temp = {map_width+border_width, 0, border_width, map_height+2*border_width};
    add_map_object(2, temp);

    #else
    object_count = 1;
    #endif



}
Map::~Map()
{//dtor
    //delete[] map_rects;//dtor
    SDL_DestroyTexture(stone_texture);
    SDL_DestroyTexture(border_texture);
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
    Object temp_obj = Object();
    //Object* temp2_obj = new Object[object_count+1];

    temp_obj.setRect(obj_rect);
    temp_obj.setId(obj_id);

    //writing properties to the object
    if(obj_id == 2)
    {
        temp_obj.setDestroyable(false);
    }

    temp_obj.calc_points();   //calculating new points

    map_rects.push_back(temp_obj);

    object_count++;
}


/*
funkcja do usuwania z mapy jednego obiektu o numerze obj_no


*/
void Map::delete_map_object(int obj_no)
{
    map_rects.erase(map_rects.begin()+obj_no);
    object_count--;
}

void Map::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, BLACK, 255);
    //SDL_RenderDrawLine(renderer, 100, 200, 300, 200);
    SDL_Rect tempRect;

    for(int i=0; i<object_count; i++)
    {
        tempRect = map_rects[i].getRect();

        SDL_RenderDrawRect(renderer, &tempRect);
        switch(map_rects[i].getId())
        {
        case 0:
            break;
        case 1:
            SDL_RenderCopy(renderer, stone_texture, NULL, &tempRect);
            break;
        case 2:
            SDL_RenderCopy(renderer, border_texture, NULL, &tempRect);
            break;
        default:
            break;
        }
    }

    //cout<<"Rozmiar obiektu: "<<sizeof(SDL_Rect)<<endl;
}

/*
Funkcja sprawdza czy podany rect koliduje z mapą i zwraca true jeśli tak

*/
Int_bool Map::collide_rect(SDL_Rect r)
{
    Int_bool ret;

    for(int i=0; i<object_count; i++)
    {
        SDL_Rect m = map_rects[i].getRect();

        bool x_collides = false;
        bool y_collides = false;

        if( (r.x+r.w < m.x+m.w) && (r.x+r.w > m.x) )//kolizja z prawej na x gracz=>obiekt
        {
            #if COLLIDE_TEST == 1
            cout<<"kolizja x1"<<endl;
            #endif // COLLIDE_TEST
            x_collides = true;
        }
        else if( (r.x > m.x) && (r.x < m.x+m.w) )//kolizja z lewej na x obiekt<=gracz
        {
            #if COLLIDE_TEST == 1
            cout<<"kolizja x2"<<endl;
            #endif // COLLIDE_TEST
            x_collides = true;
        }
        else if( (r.x < m.x) && (r.x+r.w > m.x+m.w) )//kolizja z lewej na x obiekt<=gracz
        {
            #if COLLIDE_TEST == 1
            cout<<"kolizja x3"<<endl;
            #endif // COLLIDE_TEST
            x_collides = true;
        }

        if( (r.y < m.y+m.h) && (r.y > m.y) )//gracz na dole idzie do góry, kolizja na y
        {
            #if COLLIDE_TEST == 1
            cout<<"kolizja y1"<<endl;
            #endif // COLLIDE_TEST
            y_collides = true;
        }
        else if( (r.y+r.h < m.y+m.h) && (r.y+r.h > m.y) )//gracz na górze idzie do dołu, kolizja y
        {
            #if COLLIDE_TEST == 1
            cout<<"kolizja y2"<<endl;
            #endif // COLLIDE_TEST
            y_collides = true;
        }
        else if( (r.y < m.y) && (r.y+r.h > m.y+m.h) )//kolizja gracza mniejszego od obiektu, który dotyka od środka
        {
            #if COLLIDE_TEST == 1
            cout<<"kolizja y3"<<endl;
            #endif // COLLIDE_TEST
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
    #define NO_OF_BLOCKS 2
    SDL_Surface* Surf_Temp = NULL;
    const char* filename[NO_OF_BLOCKS] = {"bmp/stone.bmp", "bmp/border.bmp"};//Give the file location to block textures
    SDL_Texture* textures[NO_OF_BLOCKS] = {NULL, NULL};
    int* a[2];
    int b,c;

    for(int i=0; i<NO_OF_BLOCKS; i++)
    {
        if( (Surf_Temp = SDL_LoadBMP(filename[i]) ) == NULL)
        {
            cout<<"błąd";
            return false;
        }

        if((textures[i] = SDL_CreateTextureFromSurface(render, Surf_Temp)) == NULL)
        {
            cout<<"błąd";
            return false;
        }

        SDL_FreeSurface(Surf_Temp);
    }

    stone_texture = textures[0];
    border_texture = textures[1];

    return true;
}

/*
    move_camera - moves all the objects inside map_rects by x and y dimensions
*/
void Map::move_camera(int x, int y)
{
    for(int i=0; i<object_count; i++)
    {
        SDL_Rect tempRect = map_rects[i].getRect();
        tempRect.x += x;
        tempRect.y += y;

        map_rects[i].setRect(tempRect);

        for(int j=0; j<4; j++)
        {
            map_rects[i].points[j].x += x;
            map_rects[i].points[j].y += y;
        }
        map_rects[i].calc_points();
   }
}

void Map::draw_traj(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, BLACK, 255);
    int x1, y1, x2, y2;
    float a,b;


    for(int i=0; i<object_count; i++)
    {
        for(int j=0; j<4; j++)
        {
            x1 = map_rects[i].points[j].x - 100;
            y1 = (int) (map_rects[i].a[j]*x1 + map_rects[i].b[j]);

            x2 = map_rects[i].points[j].x + 100;
            y2 = (int) (map_rects[i].a[j]*x2 + map_rects[i].b[j]);
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        }
    }
}

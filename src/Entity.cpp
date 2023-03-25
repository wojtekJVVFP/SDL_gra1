#include <iostream>
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

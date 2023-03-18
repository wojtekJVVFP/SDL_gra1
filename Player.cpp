#include <iostream>
#include "CApp.h"
#include "Player.h"
#include "color_definition.h"

using namespace std;

Player::Player(int x, int y)
{
    pos_x = x;
    pos_y = y;
    player_texture = NULL;
    player_width = 0;
    player_height = 0;
    SDL_Rect player_rect;
}

Player::~Player()
{
   SDL_DestroyTexture(player_texture);
}

int Player::get_x()
{
   return pos_x;
}


int Player::get_y()
{
  return pos_y;
}

bool Player::load_player_texture(const char* filename, SDL_Renderer* render)
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


    if((player_texture = SDL_CreateTextureFromSurface(render, Surf_Temp)) == NULL)
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

void Player::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, WHITE, 255);
    player_rect.x = pos_x;
    player_rect.y = pos_y;

    SDL_RenderCopy(renderer, player_texture, NULL, &player_rect);
}

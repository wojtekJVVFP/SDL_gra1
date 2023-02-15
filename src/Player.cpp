#include "CApp.h"
#include "Player.h"

Player::Player(int x, int y)
{
    pos_x = x;
    pos_y = y;
    player_texture = NULL;
}

Player::~Player()
{

}

int Player::get_x()
{
   return pos_x;
}


int Player::get_y()
{
  return pos_y;
}

bool Player::load_player_texture(char* filename, SDL_Renderer* render)
{
    SDL_Surface* Surf_Temp = NULL;

    if( (Surf_Temp = SDL_LoadBMP(filename) ) == NULL)
    {
        return false;
    }

    if( (player_texture = SDL_CreateTextureFromSurface(render, Surf_Temp) ) == NULL)
    {
        return false;
    }
    return true;

}

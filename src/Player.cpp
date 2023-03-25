#include <iostream>
#include "CApp.h"
#include "Player.h"
#include "color_definition.h"

using namespace std;

Player::Player(int x, int y)
: Entity(x,y)   //Lista inicjalizacyjna - wywołanie konstruktora klasy nadrzędnej
{

}

Player::~Player()
{
    SDL_DestroyTexture(texture);
}


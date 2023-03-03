#include "CApp.h"
#include "Map.h"
#include "color_definition.h"

Map::Map()
{//ctor
    map_rects[0] = {100,5,30,30};

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

    SDL_RenderDrawRect(renderer, &(map_rects[0]));
}


bool player_collides(Player* p)
{
    if
    return false;
}


#include <iostream>
#include "CSurface.h"
#include "Player.h"
#include "Map.h"
#include "color_definition.h"

using namespace std;

CSurface::CSurface()
{
}

SDL_Texture* CSurface::OnLoad(char* File, SDL_Renderer* render)
{
    SDL_Surface* Surf_Temp = NULL;
    SDL_Texture* Texture_Return = NULL;

    if((Surf_Temp = SDL_LoadBMP(File)) == NULL) {
        return NULL;
    }

    Texture_Return = SDL_CreateTextureFromSurface(render, Surf_Temp);

    return Texture_Return;
}

bool CSurface::OnDraw(SDL_Texture* texture, SDL_Renderer* renderer, class Player* p)
{
    if(texture == NULL)
    {
        return false;
    }

    Map mapa;
    Player p1;
    Player p2;


    p1.pos_x = 10;

    p2.pos_x = p->get_x();

    //cout<<p1.get_x()<<" "<<p2.get_x()<<endl;


    SDL_SetRenderDrawColor(renderer, WHITE, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, BLACK, 255);
    mapa.render(renderer);
    p->render(renderer);


//problem z ładowaniem tekstury gracza, inne tekstury ładuje dobrze
    //p.load_player_texture("bmp/dodge.bmp", renderer);

    SDL_RenderPresent(renderer);



    return true;
}

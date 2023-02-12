#include "CSurface.h"

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

bool CSurface::OnDraw(SDL_Texture* texture, int X, int Y, SDL_Renderer* renderer)
{
    if(texture == NULL)
    {
        return false;
    }
    #define WHITE 255,255,255
    SDL_Rect DestR;

    DestR.x = 500;
    DestR.y = 300;
    DestR.h = 100;
    DestR.w = 200;
    SDL_Rect src = {10,10,100,50};
    SDL_Rect dst = {0,0,100,50};

    src.x = X;
    src.y = Y;

    SDL_SetRenderDrawColor(renderer, WHITE, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderDrawLine(renderer, 10, 10, 300, 100);

    SDL_RenderDrawRect(renderer, &DestR);
    SDL_RenderCopy(renderer, texture, &dst, &src);
    SDL_RenderPresent(renderer);

    //SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

    return true;
}

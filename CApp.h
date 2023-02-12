#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL.h>
#include "CSurface.h"
#include "keys_handling.h"

#define WIDTH 800
#define HEIGHT 600

/*
Jak dołączyć dodatkową pomocniczą klasę do obsługi klawiszy?
Ma być dostęp do pos_x i pos_y
- Musi być dostęp z wnętrza klasy CApp i funkcji OnEvent
Na razie dodano wszystko do klasy CApp

*/

class CApp
{
private:
    bool Running;
    SDL_Surface* Surf_Display;
    SDL_Window* Window;
    SDL_Surface* Surf_Test;
    SDL_Renderer* renderer;
    SDL_Texture* Texture_Display;
    SDL_Texture* Texture;



public:
    CApp();
    int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void OnCleanup();

    unsigned int pos_x;
    unsigned int pos_y;
};


#endif // CAPP_H_INCLUDED

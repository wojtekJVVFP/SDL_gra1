#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL.h>
#include "CSurface.h"
#include "keys_handling.h"
#include "Player.h"
#include "Npc.h"
#include "Map.h"

#define WIDTH 800
#define HEIGHT 600

#define COLLIDE_TEST 0

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

    class Player p;
    class Npc n;
    class Map mapa;


public:
    CApp();
    int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event* Event, class Keys_Handling* keys);
    bool timer();
    void OnLoop();
    void OnRender();
    void OnCleanup();
};


#endif // CAPP_H_INCLUDED

#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL.h>

class CSurface {
private:
public:
    CSurface();

public:
    static SDL_Texture* OnLoad(const char* File, SDL_Renderer* render);
    static bool OnDraw(SDL_Texture* texture, SDL_Renderer* render, class Player* p, class Map* m);

    friend class CApp;
};

#endif

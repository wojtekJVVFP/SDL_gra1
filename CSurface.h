#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL.h>

class CSurface {
private:
public:
    CSurface();

public:
    static SDL_Texture* OnLoad(char* File, SDL_Renderer* render);
    static bool OnDraw(SDL_Texture* texture, int X, int Y, SDL_Renderer* render);
};

#endif

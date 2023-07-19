#include "CApp.h"
#include <iostream>

using namespace std;

bool CApp::OnInit() {
    //int rendererFlags = SDL_RENDERER_ACCELERATED;
    //int windowFlags = 0;

    cout<<"Wersja C++: "<<__cplusplus<<endl;//Piszę w c++ 14

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }
    //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.


    if((Window = SDL_CreateWindow(
        "hello_fdl2",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN)) == NULL) return false;

    Surf_Display = SDL_GetWindowSurface(Window);
    if((renderer = SDL_CreateRenderer(Window, -1, 0)) == NULL) //renderer initialization
    {
        return false;
    }
//C:\Users\jvvfp\OneDrive\codeblocks\SDL_gra1\bmp
    if((Texture = CSurface::OnLoad("bmp/dodge2.bmp", renderer)) == NULL)
    {
        return false;
    }
    if((Texture_Display = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR32, SDL_TEXTUREACCESS_STATIC,WIDTH, HEIGHT)) == NULL)
    {
        return false;
    }
    if(p.load_texture("bmp/test.bmp", renderer) == true)
    {
        cout<<"tekstura gracza załadowana OK"<<endl;
    }
    else
    {
        return false;
    }

    if(n.load_texture("bmp/npc.bmp", renderer) == true)
    {
        cout<<"tekstura gracza załadowana OK"<<endl;
    }
    else
    {
        return false;
    }


    if(mapa.load_object_textures(renderer) == true)
    {
        cout<<"tekstury obiektów załadowane OK"<<endl;
    }

    return true;
}

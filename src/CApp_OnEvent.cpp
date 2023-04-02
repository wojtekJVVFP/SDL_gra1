#include "CApp.h"
#include <iostream>

using namespace std;


void CApp::OnEvent(SDL_Event* Event, Keys_Handling* keys)
{
    //SDL_Event event;
    switch (Event->type)
    {
        case SDL_QUIT:
            Running = false;
            break;
        case SDL_KEYDOWN:
            cout<<"keydown ";
            keys -> key_down(&Event->key, &p, &mapa, &n);
            cout<<p.pos_x;

        case SDL_KEYUP:
            cout<<"keyup ";
            keys -> key_up(&Event->key);

        default:
            break;
    }

}

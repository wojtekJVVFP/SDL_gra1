#include "CApp.h"

void CApp::OnRender()
{
    //SDL_RenderClear(renderer)

    CSurface::OnDraw(Texture, renderer, &p);
    //CSurface::OnDraw(Texture, 0, 0, renderer);

}

//definicja klasy - jest dostęp do każdego elementu

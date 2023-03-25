#include "CApp.h"

void CApp::OnRender()
{
    //SDL_RenderClear(renderer)

    CSurface::OnDraw(Texture, renderer, &p, &mapa, &n);

}

//definicja klasy - jest dostęp do każdego elementu

#include "CApp.h"

void CApp::OnRender()
{
    CSurface::OnDraw(Texture, p.pos_x, p.pos_y, renderer);
    //CSurface::OnDraw(Texture, 0, 0, renderer);

}

//definicja klasy - jest dostęp do każdego elementu

#include "CApp.h"

void CApp::OnRender()
{
    CSurface::OnDraw(Texture,pos_x, pos_y, renderer);
    //CSurface::OnDraw(Texture, 0, 0, renderer);

}


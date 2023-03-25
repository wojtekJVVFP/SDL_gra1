#include "CApp.h"

void CApp::OnCleanup()
{
    SDL_FreeSurface(Surf_Display);
    SDL_FreeSurface(Surf_Test);
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(Texture);
    SDL_DestroyTexture(Texture_Display);
    SDL_Quit();
}

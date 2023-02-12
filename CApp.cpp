#include "CApp.h"

CApp::CApp()
{
    Surf_Display = NULL;
    Surf_Test = NULL;
    Window = NULL;
    renderer = NULL;
    Running = true;

    pos_x = 0;
    pos_y = 0;
}

int CApp::OnExecute()
{
    if(OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;

    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

void Read_PosXY();

int main(int argc, char* argv[])
{
    CApp theApp;
    Keys_Handling keys;

    return theApp.OnExecute();
}

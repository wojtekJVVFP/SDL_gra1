#include "CApp.h"

CApp::CApp()
{
    Surf_Display = NULL;
    Surf_Test = NULL;
    Window = NULL;
    renderer = NULL;
    Running = true;
}

int CApp::OnExecute()
{
    if(OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;
    Keys_Handling keys;
//Co zrobić, żeby obiekt był dostęny we wszystkich funkcjach

    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event, &keys);
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

    return theApp.OnExecute();
}

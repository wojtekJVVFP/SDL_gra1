#include "CApp.h"
/*

+ Jak użyskiwać dostęp do informacji o graczu wewnątrz klasy CSurface - jest tam metoda do rysowania
+ można przekazać gracza/y oraz mapki jako argument do funkcji rysującej

+ Jak uzyskać rozmiar gracza tj. tekstury bądź powierzchni? - potrzebne do poprawnego kopiowania tekstury gracza do tekstury tła
+ mie ładuje się gracz, prawdopodobnie problem z ładowaniem tekstury - tekstura ok,
po przekazaniu obiektu Player przez wskaźnik zadziałało
+ dodana funkcja wykrywająca kolizję gracza z obiektami mapki
- pisać dynamiczne dodawanie obiektów na ekranie, czyli będzie drugi wskaźnik z tablicą o 1 większą, kopiowanie starej tablicy do nowej, kasowanie starego wskaźnika, przypisanie nowego wsk
- Pisać klasę do rysowania mapki na ekranie



*/

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

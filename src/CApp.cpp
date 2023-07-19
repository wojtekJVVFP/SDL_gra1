#include "CApp.h"
/*

+ Jak użyskiwać dostęp do informacji o graczu wewnątrz klasy CSurface - jest tam metoda do rysowania
+ można przekazać gracza/y oraz mapki jako argument do funkcji rysującej

+ Jak uzyskać rozmiar gracza tj. tekstury bądź powierzchni? - potrzebne do poprawnego kopiowania tekstury gracza do tekstury tła
+ mie ładuje się gracz, prawdopodobnie problem z ładowaniem tekstury - tekstura ok,
po przekazaniu obiektu Player przez wskaźnik zadziałało
+ dodana funkcja wykrywająca kolizję gracza z obiektami mapki
+ pisać dynamiczne dodawanie obiektów na ekranie, czyli będzie drugi wskaźnik z tablicą o 1 większą, kopiowanie starej tablicy do nowej, kasowanie starego wskaźnika, przypisanie nowego wsk
+ dodawanie nowego obiektu na ekranie poprzez wciśnięcie klawisza a
- Pisać klasę do rysowania mapki na ekranie
+ napisać, żeby łatwiejsze było dodawanie różnych obiektów łącznie z teksturami na ekranie. Mapka mogłaby się składać z obiektów, a nie prostokątów, w zależności od wybranego id
 będzie inny kształt i tekstura. Id obiektu będzie dawać informację odnośnie tekstury i rozmiarów prostokąta do rysowania, dodatkowe właściwości obiektu to położenie
    - Obiekty na ekranie będą rysowane razem z teksturami - tekstury będę ładowane
    - Pisać strukturę do przechowania informacji o obiekcie: SDL_Rect, id, które będzie później wykorzystane do narysowania w render
    + dane o obiektach w tablicy map_rects - będą struktury object_data
    - informacje o stosowanych numerach tekstur we funkcji render
    - tesktury zostaną załadowane w kolejności do tablicy tekstur (tablica wskaźników na kolejne tekstury)
    - można zacząć liczenie od 0, żeby numery id odpowiadały 1:1 położeniom w obrębie tablicy tekstur - 0 - brak tekstury, 1 - kamień,
    - ładowanie tekstur z pliku w load_object_textures
+ do dodania npc, który się porusza we funkcji OnLoop na początek niech przenika przez obiekty
- do dodania punkty dla gracza po dotknięciu wybranego obiektu. Obiekt powinien się pojawiać w losowych miejscach i znikać po dotknięciu przez gracza
- do poprawy
*/

CApp::CApp()
: p(Player(500,100))    //initialization of p member of a class, it don't need to be a default constructor

{
    Surf_Display = NULL;    //initializing pointers
    Surf_Test = NULL;
    Window = NULL;
    renderer = NULL;
    Texture_Display = NULL;
    Texture = NULL;
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

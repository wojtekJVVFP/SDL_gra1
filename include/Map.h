#ifndef MAP_H
#define MAP_H

/*

Klasa

*/
class Map
{
    public:
        Map();
        virtual ~Map();
        void render(SDL_Renderer* renderer);

        friend class CApp;

    protected:
        SDL_Rect map_rects[5];

    private:
};

#endif // MAP_H

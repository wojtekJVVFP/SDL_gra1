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
        bool player_collides(SDL_Rect r);

        friend class CApp;
        friend class Keys_Handling;

    protected:
        SDL_Rect map_rects[5];

    private:
};

#endif // MAP_H

#ifndef MAP_H
#define MAP_H

struct Int_bool //struktura używana do zwracania wartości przez funkcję do badania kolizji
{
    int ret_int;
    bool ret_bool;
};

/*

Klasa

*/
class Map
{
    public:
        Map();
        virtual ~Map();
        void add_map_object(int obj_id, SDL_Rect object_rect);
        void render(SDL_Renderer* renderer);
        Int_bool player_collides(SDL_Rect r);

        friend class CApp;
        friend class Keys_Handling;

    protected:
        int object_count;   //ilość obiektów do rozmiaru p_map_rects
        SDL_Rect* map_rects;

    private:
};


#endif // MAP_H

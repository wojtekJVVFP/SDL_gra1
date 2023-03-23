#ifndef MAP_H
#define MAP_H

struct Int_bool //struktura używana do zwracania wartości przez funkcję do badania kolizji
{
    int ret_int;
    bool ret_bool;
};

struct Object
{
    int id;
    SDL_Rect rect;
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
        void delete_map_object(int obj_no);
        void render(SDL_Renderer* renderer);
        Int_bool collide_rect(SDL_Rect r);
        bool load_object_textures(SDL_Renderer* render);

        friend class CApp;
        friend class Keys_Handling;

    protected:
        int object_count;   //ilość obiektów do rozmiaru p_map_rects
        Object* map_rects;
        SDL_Texture* stone_texture;

    private:
};


#endif // MAP_H

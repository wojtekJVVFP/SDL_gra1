#ifndef MAP_H
#define MAP_H

struct Int_bool //struktura używana do zwracania wartości przez funkcję do badania kolizji
{
    int ret_int;
    bool ret_bool;
};

struct Point
{
    int x;
    int y;
};

class Object
{
public:
    Object();
    ~Object();
    void calc_points();
    bool is_destroyable();
    friend class Map;
    friend class Entity;
private:
    int id;
    bool destroyable;
    SDL_Rect rect;
    Point points[4];    //storing rect points
    float a[4];         //a and b coefficients from straight formula y = a*x + b
    float b[4];
    /*  3 *     2 *


        0 *     1 * */

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
        void move_camera(int x, int y);
        void draw_traj(SDL_Renderer* renderer);

        friend class CApp;
        friend class Keys_Handling;
        friend class Npc;
        friend class Entity;

    protected:
        int object_count;   //ilość obiektów do rozmiaru p_map_rects
        Object* map_rects;
        SDL_Texture* stone_texture;
        SDL_Texture* border_texture;

    private:
};


#endif // MAP_H

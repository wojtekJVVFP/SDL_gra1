#ifndef ENTITY_H
#define ENTITY_H

#include "geometry.h"

class Entity
{
    public:
        Entity(int x=0, int y=0);   //Musi tu być wpisany konstruktor domyślny, czyli podane domyślne wartości
        ~Entity();
        Entity(const Entity& other);

        double get_x();
        double get_y();
        bool load_texture(const char* filename, SDL_Renderer* render);
        void render(SDL_Renderer* renderer);
        bool collide_rect(SDL_Rect r);
        void calc_traj(double dx, double dy);
        Increments calc_collision(class Map* m, int object_no, Increments dxdy);
        void draw_traj(SDL_Renderer* renderer);


    protected:
        double pos_x;
        double pos_y;
        SDL_Texture* texture;
        int player_width;
        int player_height;
        SDL_Rect player_rect;
        double a,b;  //a, b coefficients of straight line y=ax+b, trajectory of entity
        SDL_Point p_col[4];
    private:
};

#endif // ENTITY_H

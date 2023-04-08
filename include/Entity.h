#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
    public:
        Entity(int x=0, int y=0);   //Musi tu być wpisany konstruktor domyślny, czyli podane domyślne wartości
        ~Entity();
        Entity(const Entity& other);

        int get_x();
        int get_y();
        bool load_texture(const char* filename, SDL_Renderer* render);
        void render(SDL_Renderer* renderer);
        bool collide_rect(SDL_Rect r);
        void calc_traj(int dx, int dy);
        void draw_traj(SDL_Renderer* renderer);


    protected:
        int pos_x;
        int pos_y;
        SDL_Texture* texture;
        int player_width;
        int player_height;
        SDL_Rect player_rect;
        float a,b;  //a, b coefficients of straight line y=ax+b
    private:
};

#endif // ENTITY_H

#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(int x=0, int y=0);
        virtual ~Player();
        int get_x();
        int get_y();
        bool load_player_texture(char* filename, SDL_Renderer* render);
        void render(SDL_Renderer* renderer);

        friend class Keys_Handling;
        friend class CApp;
        friend class CSurface;

    protected:

    private:
        int pos_x;
        int pos_y;
        SDL_Texture* player_texture;
        unsigned int player_width;
        unsigned int player_height;
        SDL_Rect player_rect;

};

#endif // PLAYER_H

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

        friend class Keys_Handling;
        friend class CApp;
        friend class CSurface;

    protected:

    private:
        int pos_x;
        int pos_y;
        SDL_Texture* player_texture;

};

#endif // PLAYER_H

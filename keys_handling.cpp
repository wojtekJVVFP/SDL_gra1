#include "keys_handling.h"
#include <iostream>

using namespace std;

Keys_Handling::Keys_Handling(int u, int d, int l, int r)
{
    up = u;
    down = d;
    left = l;
    right = r;
    step = 5;
}
void Keys_Handling::key_up(SDL_KeyboardEvent* event)
{
    if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
            up = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			down = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
            left = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
            right = 0;
		}
		if (event->keysym.scancode == SDL_SCANCODE_A)
		{

		}
	}
}

/*
Jak uprościć wykonywanie
jak skrócić kod poniższej funkcji?

*/


void Keys_Handling::key_down(SDL_KeyboardEvent* event, class Player* p, class Map* m)
{
    if (event->repeat <= 1)
	{
		SDL_Rect temp_rect = p->player_rect;
		Int_bool t;

		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
            up = 1;

            temp_rect.y -= step;
            t = m->player_collides(temp_rect);
            if((t.ret_bool) == false)
            {
                p->pos_y -= step;
            }
            else
            {
                cout<<"Nr obiektu: "<<t.ret_int<<endl;
            }

            cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			down = 1;

			temp_rect.y += step;
            if((m->player_collides(temp_rect).ret_bool) == false)
            {
               p->pos_y += step;
            }
			cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
            left = 1;

            temp_rect.x -= step;
            if((m->player_collides(temp_rect).ret_bool) == false)
            {
               p->pos_x -= step;
            }

            cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
            right = 1;

            temp_rect.x += step;
            if((m->player_collides(temp_rect).ret_bool) == false)
            {
               p->pos_x += step;
            }
            cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}
		if (event->keysym.scancode == SDL_SCANCODE_A)
		{
            SDL_Rect stone = {p->get_x()+p->player_width+1, p->get_y(), 100,100};
            m->add_map_object(2, stone);
		}
	}

}

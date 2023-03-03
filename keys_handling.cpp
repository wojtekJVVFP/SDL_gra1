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
	}
}

void Keys_Handling::key_down(SDL_KeyboardEvent* event, class Player* p, class Map* m)
{
    if (event->repeat <= 1)
	{
		SDL_Rect temp_rect = p->player_rect;

		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
            up = 1;

            temp_rect.y -= step;
            if((m->player_collides(temp_rect)) == false)
            {
               p->pos_y -= step;
            }

            cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			down = 1;

			temp_rect.y += step;
            if((m->player_collides(temp_rect)) == false)
            {
               p->pos_y += step;
            }
			cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
            left = 1;

            temp_rect.x -= step;
            if((m->player_collides(temp_rect)) == false)
            {
               p->pos_x -= step;
            }

            cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
            right = 1;

            temp_rect.x += step;
            if((m->player_collides(temp_rect)) == false)
            {
               p->pos_x += step;
            }
            cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}
	}

}

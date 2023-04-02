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
		if (event->keysym.scancode == SDL_SCANCODE_S)
		{

		}
	}
}

/*
Jak uprościć wykonywanie
jak skrócić kod poniższej funkcji?

*/


void Keys_Handling::key_down(SDL_KeyboardEvent* event, class Player* p, class Map* m, class Npc* n)
{
    SDL_Rect temp_rect = p->player_rect;
    Int_bool t;
    int range = 20;  //odległość do skasowania obiektu

    if (event->repeat <= 1)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
            up = 1;

            temp_rect.y -= step;

            t = m->collide_rect(temp_rect);
            if((t.ret_bool) == false)
            {
                //p->pos_y -= step;
                m->move_camera(0, step);
                n->move_entity(0, step);
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
            if((m->collide_rect(temp_rect).ret_bool) == false)
            {
               //p->pos_y += step;
               m->move_camera(0, -1*step);
               n->move_entity(0, -1*step);
            }
			cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
            left = 1;

            temp_rect.x -= step;
            if((m->collide_rect(temp_rect).ret_bool) == false)
            {
               //p->pos_x -= step;
               m->move_camera(step, 0);
               n->move_entity(step, 0);
            }

            cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
            right = 1;

            temp_rect.x += step;
            if((m->collide_rect(temp_rect).ret_bool) == false)
            {
               //p->pos_x += step;
               m->move_camera(-1*step, 0);
               n->move_entity(-1*step, 0);
            }
            cout<<p->get_x()<<" "<<p->get_y()<<endl;
		}
		if (event->keysym.scancode == SDL_SCANCODE_A)
		{
            SDL_Rect block = {p->get_x()+p->player_width+1, p->get_y(), 100,100};

            if(m->collide_rect(block).ret_bool == false) //gdy nie ma kolizji z innymi obiektami
            {
               m->add_map_object(1, block);
            }

		}
		if (event->keysym.scancode == SDL_SCANCODE_S)
		{
            temp_rect.w += 2*range;
            temp_rect.h += 2*range;
            temp_rect.x -= range;
            temp_rect.y -= range;
            t = m->collide_rect(temp_rect);
            if((t.ret_bool) == true)
            {
                m->delete_map_object(t.ret_int);
            }
		}
	}
    cout<<endl;
}

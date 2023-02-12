#include "keys_handling.h"
#include <iostream>

using namespace std;

Keys_Handling::Keys_Handling()
{

}
void Keys_Handling::key_up(SDL_KeyboardEvent* event, unsigned int* pos_x, unsigned int* pos_y)
{

}

void Keys_Handling::key_down(SDL_KeyboardEvent* event, unsigned int* pos_x, unsigned int* pos_y)
{
    if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			*pos_x += 10;
			cout<<*pos_x<<endl;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			*pos_x -= 10;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{

		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{

		}
	}

}

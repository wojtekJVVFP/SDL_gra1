#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				Running = false;
				break;
            case SDL_KEYDOWN:
                Keys_Handling::key_down(&event.key, &pos_x, &pos_y);
            case SDL_KEYUP:
                Keys_Handling::key_up(&event.key, &pos_x, &pos_y);

			default:
				break;
		}
	}

}

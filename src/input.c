#include "../dependencies/game.h"

/**
 * inputhandler - checks the type of keyboard input
 * @app: direction object
 *
 * Return: boolean for key events
 */
bool inputhandler(sdl_elements *app)
{
	SDL_Event event;
	bool output = true;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				output = false;
				break;
			case SDL_KEYUP:
				key_released(&event.key, app);
				break;
			case SDL_KEYDOWN:
				key_pressed(&event.key, app);
				break;
			default:
				break;
		}
	}
	return (output);
}

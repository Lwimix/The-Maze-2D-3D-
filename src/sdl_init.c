#include "../dependencies/game.h"

/**
 * init - initialises sdl elements and player object position
 * @app: object with renderer and window elements
 * @player: player object
 *
 * Return: initialised sdl elements
 */
sdl_elements init(sdl_elements app, Object *player)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Error initialising: %s\n", SDL_GetError());
		return (app);
	}
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		printf("%d\n", IMG_Init(IMG_INIT_PNG));
		printf("Error initialising img: %s\n", SDL_GetError());
		return (app);
	}
	app.win = SDL_CreateWindow("The Maze",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480, 0);
	if (!app.win)
	{
		printf("Error creating window: %s\n", SDL_GetError());
		IMG_Quit();
		return (app);
	}
	app.rend = SDL_CreateRenderer(app.win, -1, 0);
	if (!app.rend)
	{
		printf("Error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(app.win);
		IMG_Quit();
		return (app);
	}
	player->x = 100;
	player->y = 100;
	return (app);
}

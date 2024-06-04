#include "../dependencies/game.h"

/**
 * main - check the code
 * @argc: number of arguments
 * @argv: actual arguments
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	(void)argc, (void)argv;
	sdl_elements app;
	Object player;
	bool loop = true;

	memset(&app, 0, sizeof(sdl_elements));
	memset(&player, 0, sizeof(Object));
	app = init(app, &player);
	if (!app.win || !app.rend)
		return (1);
	while (loop)
	{
		loop = inputhandler(&app);
		if (!loop)
			break;
		update_pos(app, &player);
		loop = draw(&app, &player);
	}
	SDL_Quit();
	return (0);
}

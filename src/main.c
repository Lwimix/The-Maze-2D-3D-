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
	player.x = 100;
	player.y = 100;
	app = init(app);
	if (!app.win || !app.rend)
		return (1);
	while (loop)
	{
		loop = inputhandler(&app);
		if (!loop)
			break;
		if (app.up)
			player.y -= 1;
		if (app.down)
			player.y += 1;
		if (app.left)
			player.x -= 1;
		if (app.right)
			player.x += 1;
		loop = draw(&app, &player);
	}
	SDL_Quit();
	return (0);
}

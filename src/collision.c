#include "../dependencies/game.h"

/**
 * collide - collision check
 * @app: direction object
 * @player: player object
 * @collision: true if collision occurred
 *
 * Return: nothing
 */
void collide(sdl_elements *app, Object *player, SDL_bool collision)
{
	if (collision)
	{
		if (app->up)
			player->y += 1;
		if (app->down)
			player->y -= 1;
		if (app->left)
			player->x += 1;
		if (app->right)
			player->x -= 1;
	}
}

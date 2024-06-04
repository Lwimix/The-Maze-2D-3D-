#include "../dependencies/game.h"

/**
 * update_pos - updates player position during movement
 * @app: direction object
 * @player: player object
 *
 * Return: nothing
 */
void update_pos(sdl_elements app, Object *player)
{
		if (app.up)
			player->y -= 1;
		if (app.down)
			player->y += 1;
		if (app.left)
			player->x -= 1;
		if (app.right)
			player->x += 1;
}

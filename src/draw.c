#include "../dependencies/game.h"

/**
 * draw - draws background and player
 * @app: direction object
 * @player: player object
 *
 * Return: true for success
 */
bool draw(sdl_elements *app, Object *player)
{
	SDL_Rect gamer = {player->x, player->y, 30, 30};
	SDL_Rect inv_wall = {0, 0, 640, 480};
	SDL_Texture *map = IMG_LoadTexture(app->rend, "./resources/Block_map.png");
	SDL_bool collision;
	SDL_Rect block = {400, 200, 70, 70};
	SDL_Texture *one_block = NULL;

	if (!map)
	{
		printf("Error creating map texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(app->rend);
		SDL_DestroyWindow(app->win);
		return (false);
	}
	player->tex = IMG_LoadTexture(app->rend, "./resources/dot.png");
	if (!player->tex)
	{
		printf("Error creating texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(app->rend);
		SDL_DestroyWindow(app->win);
		return (false);
	}
	collision = invisiWall(app, &gamer, &block, &one_block);
	collide(app, player, collision);
	SDL_RenderCopy(app->rend, map, NULL, &inv_wall);/*map drawing*/
	SDL_RenderCopy(app->rend, one_block, NULL, &block);
	SDL_RenderCopy(app->rend, player->tex, NULL, &gamer);
	SDL_RenderPresent(app->rend);
	return (true);
}

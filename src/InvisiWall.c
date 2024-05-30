#include "../dependencies/game.h"

/**
 * invisiWall - wall drawings
 * @app: direction object
 * @gamer: player object
 * @b: block object
 * @t: texture
 *
 * Return: true for collision
 */
SDL_bool invisiWall(sdl_elements *app, SDL_Rect *gamer, SDL_Rect *b,
		SDL_Texture **t)
{
	SDL_bool collision;

	*t = IMG_LoadTexture(app->rend, "./resources/Block.png");
	if (!(*t))
	{
		printf("Error creating block texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(app->rend);
		SDL_DestroyWindow(app->win);
		return (false);
	}
	collision = SDL_HasIntersection(gamer, b);
	return (collision);
}

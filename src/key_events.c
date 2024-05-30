#include "../dependencies/game.h"

/**
 * key_pressed - checks if key pressed
 * @event: type of key
 * @app: direction object
 *
 * Return: nothing
 */
void key_pressed(SDL_KeyboardEvent *event, sdl_elements *app)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_W)
			app->up = 1;
		if (event->keysym.scancode == SDL_SCANCODE_S)
			app->down = 1;
		if (event->keysym.scancode == SDL_SCANCODE_A)
			app->left = 1;
		if (event->keysym.scancode == SDL_SCANCODE_D)
			app->right = 1;
		if (app->up || app->down || app->left || app->right)
			{};
	}
}

/**
 * key_released - checks if key released
 * @event: type of key
 * @app: direction object
 *
 * Return: nothing
 */
void key_released(SDL_KeyboardEvent *event, sdl_elements  *app)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_W)
			app->up = 0;
		if (event->keysym.scancode == SDL_SCANCODE_S)
			app->down = 0;
		if (event->keysym.scancode == SDL_SCANCODE_A)
			app->left = 0;
		if (event->keysym.scancode == SDL_SCANCODE_D)
			app->right = 0;
		if (!app->up || !app->down || !app->left || !app->right)
			{};
	}
}

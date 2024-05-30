#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/glad.h>

/**
 * struct Obj - contains position coordinates and texture
 * @x: x value
 * @y: y value
 * @tex: texture
 */
typedef struct Obj
{
	int x;
	int y;
	SDL_Texture *tex;
} Object;

/**
 * struct sdl - has sdl elements and direction elements
 * @rend: sdl renderer element
 * @win: sdl window element
 * @up: up direction
 * @down: down direction
 * @left: left direction
 * @right: direction
 */
typedef struct sdl
{
	SDL_Renderer *rend;
	SDL_Window *win;
	int up;
	int down;
	int left;
	int right;
} sdl_elements;

bool inputhandler(sdl_elements *app);
sdl_elements init(sdl_elements app);
bool draw(sdl_elements *app, Object *player);
void key_pressed(SDL_KeyboardEvent *event, sdl_elements *app);
void key_released(SDL_KeyboardEvent *event, sdl_elements *app);
void collide(sdl_elements *app, Object *player, SDL_bool collision);
SDL_bool invisiWall(sdl_elements *app, SDL_Rect *gamer,
		SDL_Rect *b, SDL_Texture **t);

#endif

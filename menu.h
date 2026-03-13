#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>

int CheckCollision(SDL_Rect A, SDL_Rect B);

typedef struct button_s{
	SDL_Rect r;
	SDL_Surface* img;
}button_t;

void DrawButton(button_t* A, SDL_Surface* B);


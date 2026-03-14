#include <SDL/SDL.h>
#include <time.h>

//structures

typedef struct button_s{
	SDL_Rect r;
	SDL_Surface* img;
	int clicked;
}button_t;

typedef struct popup_s{
	SDL_Rect r;
	SDL_Surface* img;
	int vis;
}popup_t;

//functions

int CheckCollision(SDL_Rect A, SDL_Rect B);

void DrawButton(button_t* A, SDL_Surface* B);

void DrawPopup(button_t* A, popup_t* B, SDL_Surface* C);

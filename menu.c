#include "menu.h"

int CheckCollision(SDL_Rect A, SDL_Rect B)
{
    // If any of the sides from A are outside of B
    if ((A.y + A.h) <= B.y) { return 0; }
    if (A.y >= (B.y + B.h)) { return 0; }
    if ((A.x + A.w) <= B.x) { return 0; }
    if (A.x >= (B.x + B.w)) { return 0; }
    
    // If none of the sides from A are outside B
    return 1;
}

void DrawButton(button_t* A, SDL_Surface* B){
	SDL_BlitSurface(A->img, NULL, B, &A->r);
}

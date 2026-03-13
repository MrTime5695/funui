#include "menu.c"

// Test progarm for sdl windowing project
// Intented for LF1000

int main(int argc, char** argv){
	
	int quit = 0;
	
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_WM_SetCaption("GUI Test", "Funui");
	
	SDL_Surface* screen = SDL_SetVideoMode(320, 240, 16, SDL_HWSURFACE);
	// VARIABLES
	
	button_t bg;
	bg.r.x = 0;
	bg.r.y = 0;
	bg.r.w = 320;
	bg.r.h = 240;
	bg.img = IMG_Load("img/bar.png");
	
	button_t bar;
	bar.r.x = 0;
	bar.r.y = 218;
	bar.r.w = 320;
	bar.r.h = 240;
	bar.img = IMG_Load("img/bar.png");
	
	button_t play;
	play.r.x = 8;
	play.r.y = 8;
	play.r.w = 50;
	play.r.h = 24;
	play.img = IMG_Load("img/buttonbl.png");
	
	button_t mouse;
	mouse.r.x = 0;
	mouse.r.y = 0;
	mouse.r.w = 10;
	mouse.r.h = 14;
	mouse.img = IMG_Load("img/cur.png");
	
	// GAME LOOP
	SDL_Event event;
	
	while(!quit){
		while( SDL_PollEvent( &event )){
			switch( event.type ){
				case SDL_KEYDOWN:
					switch( event.key.keysym.sym ){
						case SDLK_LEFT:
							mouse.r.x -= 10;
							break;
						case SDLK_RIGHT:					
							mouse.r.x += 10;
							break;
						case SDLK_UP:					
							mouse.r.y -= 14;
							break;
						case SDLK_DOWN:					
							mouse.r.y += 14;
							break;
						case SDLK_a:                   
							break;
						case SDLK_RETURN:
							quit = 1;
							break;
						default:
							break;
					} break;
			}
			if(event.type == SDL_MOUSEMOTION){
				mouse.r.x = event.motion.x;
				mouse.r.y = event.motion.y;
				if(CheckCollision(mouse.r, play.r)){
					play.img = IMG_Load("img/buttonhv.png");
				}
				else{
					play.img = IMG_Load("img/buttonbl.png");
				}
			}
			if( event.type == SDL_MOUSEBUTTONDOWN ){
				if(event.button.button == SDL_BUTTON_LEFT){
					if(CheckCollision(mouse.r, play.r)){
						play.img = IMG_Load("img/buttoncl.png");
					}
				}
			}
		}
	SDL_FillRect(screen, &bg.r, SDL_MapRGB(screen->format, 20, 210, 200));
	DrawButton(&bar, screen);
	DrawButton(&play, screen);
	DrawButton(&mouse, screen);
	SDL_UpdateRect(screen, 0, 0, 0, 0);
	SDL_Delay(1000/60);
	}
	SDL_Delay(1000);
	SDL_Quit();
	
	return 0;
}

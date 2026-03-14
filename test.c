#include "menu.c"

// Test progarm for sdl windowing project
// Intented for LF1000

int main(int argc, char** argv){
	
	int quit = 0;
	
	int xvel, yvel;
	xvel = 0;
	yvel = 0;
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_WM_SetCaption("GUI Test", "Funui");
	
	SDL_Surface* screen = SDL_SetVideoMode(320, 240, 16, SDL_HWSURFACE);
	// VARIABLES
	
	button_t bg;
	bg.r.x = 0;
	bg.r.y = 0;
	bg.r.w = 320;
	bg.r.h = 240;
	bg.img = SDL_LoadBMP("img/bar.bmp");
	
	button_t bar;
	bar.r.x = 0;
	bar.r.y = 218;
	bar.r.w = 320;
	bar.r.h = 240;
	bar.img = SDL_LoadBMP("img/bar.bmp");
	
	button_t play;
	play.r.x = 8;
	play.r.y = 8;
	play.r.w = 50;
	play.r.h = 24;
	play.img = SDL_LoadBMP("img/buttonbl.bmp");
	play.clicked = 0;
	
	button_t mouse;
	mouse.r.x = 0;
	mouse.r.y = 0;
	mouse.r.w = 10;
	mouse.r.h = 14;
	mouse.img = SDL_LoadBMP("img/cur.bmp");
	
	popup_t msg1;
	msg1.r.x = 20;
	msg1.r.y = 60;
	msg1.r.w = 160;
	msg1.r.h = 160;
	msg1.img = SDL_LoadBMP("img/window.bmp");
	msg1.vis = 1;
	
	// GAME LOOP
	SDL_Event event;
	
	while(!quit){
		while( SDL_PollEvent( &event )){
			switch( event.type ){
				case SDL_KEYDOWN:
					
					switch( event.key.keysym.sym ){
						case SDLK_LEFT:
							 xvel = -2;
							break;
						case SDLK_RIGHT:					
							xvel = 2;
							break;
						case SDLK_UP:					
							yvel = -2;
							break;
						case SDLK_DOWN:					
							yvel = 2;
							break;
						case SDLK_a:                   
							break;
						case SDLK_RETURN:
							quit = 1;
							break;
						default:
							break;
					} break;
					case SDL_KEYUP:
					
					switch( event.key.keysym.sym ){
						case SDLK_LEFT:
							xvel = 0;
							break;
						case SDLK_RIGHT:					
							xvel = 0;
							break;
						case SDLK_UP:					
							yvel = 0;
							break;
						case SDLK_DOWN:					
							yvel = 0;
							break;
						case SDLK_a:                   
							if(CheckCollision(mouse.r, play.r)){
								play.img = SDL_LoadBMP("img/buttoncl.bmp");
								play.clicked = 1;
							}	
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
					play.img = SDL_LoadBMP("img/buttonhv.bmp");
				}
				else{
					play.img = SDL_LoadBMP("img/buttonbl.bmp");
				}
			}
			if( event.type == SDL_MOUSEBUTTONDOWN ){
				if(event.button.button == SDL_BUTTON_LEFT){
					if(CheckCollision(mouse.r, play.r)){
						play.img = SDL_LoadBMP("img/buttoncl.bmp");
					}
				}
			}
		}
	//move mouse with dpad
	mouse.r.x += xvel;
	mouse.r.y += yvel;
	
	//down right
	if((xvel == 2) && (yvel == 2)){
		xvel = 1; yvel == 1;
	}
	//up left
	if((xvel == -2) && (yvel == -2)){
		xvel = -1; yvel == -1;
	}
	//down left
	if((xvel == -2) && (yvel == 2)){
		xvel = -1; yvel == 1;
	}
	//up right
	if((xvel == 2) && (yvel == -2)){
		xvel = 1; yvel == -1;
	}
	
	
	
	if(CheckCollision(mouse.r, play.r) && (play.img != SDL_LoadBMP("img/buttoncl.bmp"))){
		play.img = SDL_LoadBMP("img/buttonhv.bmp");
	}
	else{
		play.img = SDL_LoadBMP("img/buttonbl.bmp");
	}
	//draw order
	SDL_FillRect(screen, &bg.r, SDL_MapRGB(screen->format, 20, 210, 200));
	DrawPopup(&play, &msg1, screen);
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

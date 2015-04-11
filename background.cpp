#include "SDL/SDL.h"

int main ( int artc, char* args[] )
{
	SDL_Surface* hello = NULL;
	SDL_Surface* screen = NULL;
	
	// Start SDL
	SDL_Init( SDL_INIT_EVERYTHING );
	
	// Set up screen
	screen = SDL_SetVideoMode( 350, 450, 32, SDL_SWSURFACE );

	// Load Image
	hello = SDL_LoadBMP("background.bmp");

	// Apple Image to the screen
	SDL_BlitSurface(hello, NULL, screen, NULL);

	// Update screen
	SDL_Flip(screen);

	// pause
	SDL_Delay(2000);

	// free loaded image
	SDL_FreeSurface(hello);

	// quit
	SDL_Quit();
	
return 0;
}

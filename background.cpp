#include "SDL/SDL.h"
#include <iostream>
using namespace std;

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

	bool quit = false;

	SDL_Event e;
	
	while (!quit) {
		cout << "1" << endl;
		SDL_BlitSurface(hello, NULL, screen, NULL);
		SDL_Flip(screen);
		while (SDL_PollEvent(&e) != 0){
			cout << "2" << endl;
			if (e.type == SDL_QUIT) {	
				cout << "3" << endl;
				quit = true;
			}
			// Apple Image to the screen
		//	SDL_BlitSurface(hello, NULL, screen, NULL);

			// Update screen
		//	SDL_Flip(screen);

			// pause
			//SDL_Delay(2000);

			// free loaded image
			SDL_FreeSurface(hello);
		}
	}
	
	// quit
	//SDL_Quit();
	
return 0;
}

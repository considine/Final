#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int SCREEN_HEIGHT = 450;
int SCREEN_WIDTH = 350;
bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* flappybird = NULL;
SDL_Surface* gXOut = NULL;

bool init() {
	bool success = true;
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0)
	{
		cout<<"Could not initialize, "<<endl;
		success = false;
	}
	else 
	{
		gWindow = SDL_CreateWindow( "Flappy bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if ( gWindow == NULL ) {
			cout <<"Could not create window"<<endl;
			success = false;
		}
		else gScreenSurface = SDL_GetWindowSurface( gWindow);
	}
	return success;
}

bool loadMedia() // the picture on the screen
{
	bool success = true;
	flappybird = SDL_LoadBMP( "background.bmp");
	gXOut = SDL_LoadBMP ("x.bmp");
	if (flappybird == NULL) return false;
	return true;
}

void close () {
	SDL_FreeSurface (flappybird);
	flappybird = NULL;
	
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}

int main ( int argc, char* args[] ) {
	init();
	loadMedia();
	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while ( SDL_PollEvent (&e )!= 0) {
			if (e.type ==SDL_QUIT) quit = true;
		}
		
		SDL_BlitSurface( flappybird, NULL, gScreenSurface, NULL);
		SDL_UpdateWindowSurface(gWindow);
	}	
	close();
	return 0;
}


#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int SCREEN_HEIGHT = 450;
int SCREEN_WIDTH = 350;
bool init();
SDL_Surface* loadSurface( string path );
bool loadMedia();
void close();
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_TOTAL,
};
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* flappybird = NULL;
SDL_Surface* gXOut = NULL;
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
SDL_Surface* gCurrentSurface = NULL;


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
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "background.bmp");
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface("bird.bmp");
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

SDL_Surface* loadSurface (string path) {
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if (loadedSurface == NULL ) cout <<"UNABLE TO LOAD SURFACE"<<path<<endl;
	return loadedSurface;
} 

int main ( int argc, char* args[] ) {
	init();
	loadMedia();
	bool quit = false;
	SDL_Event e;
	gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
	while (!quit) {
		while ( SDL_PollEvent (&e )!= 0) {
			if (e.type ==SDL_QUIT) quit = true;
			else if( e.type == SDL_KEYDOWN){	
				switch(e.key.keysym.sym)
				{
					case SDLK_UP:
					gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
					break;
					case SDLK_ESCAPE:
					quit = true;
					default:
					gCurrentSurface = gKeyPressSurfaces [KEY_PRESS_SURFACE_DEFAULT ];
					break;
				}
			}
		}
		
		SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL);
		SDL_UpdateWindowSurface(gWindow);
	}	
	close();
	return 0;
}


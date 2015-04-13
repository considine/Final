#include <SDL2/SDL.h>
#include <iostream>
#include "bird.h"
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
SDL_Surface* gStretchedSurface = NULL;


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
	
	flappybird = loadSurface("bird.bmp");

	
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface("bird.bmp");
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
	SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL);
	int i =0;
	while (!quit) {
		while ( SDL_PollEvent (&e )!= 0) {
			if (e.type ==SDL_QUIT) quit = true;
			else if( e.type == SDL_KEYDOWN){	
				switch(e.key.keysym.sym)
				{
					case SDLK_UP:
					gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
					SDL_Rect stretchRect;
					stretchRect.x =SCREEN_WIDTH/2-i;
					stretchRect.y =SCREEN_HEIGHT/2;
					stretchRect.w = 50;
					stretchRect.h = 50;
					SDL_BlitScaled( gCurrentSurface, NULL, gScreenSurface, &stretchRect);
							
					break;
					case SDLK_ESCAPE:
					quit = true;
					default:
					gCurrentSurface = gKeyPressSurfaces [KEY_PRESS_SURFACE_DEFAULT ];
					SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL);
					break;
				}
			}
		}
		
		SDL_UpdateWindowSurface(gWindow);
	}	
	close();
	return 0;
}


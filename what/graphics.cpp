#include "graphics.h"
#include "bird.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

using namespace std;

graphics::graphics(int height, int width) {
	SCREEN_HEIGHT = height;
	SCREEN_WIDTH = width;
	jack.setInitial(SCREEN_HEIGHT/2, SCREEN_WIDTH/2); // sets the inital x and y of the bird "jack"
	init();  //initializes window
	loadMedia();  //loads images
	menu();

}

graphics::~graphics() {
	for (int i = 0; i < 5; i++ ) { // for all of the surfaces, clear if exists
		if (whichSurface[i] != NULL) {
	//		SDL_FreeSurface(whichSurface[i]);
	//		whichSurface[i] = NULL;                  //FREE ALL SURFACES
		}
	}
	SDL_DestroyWindow (gWindow);   //FREE THE WINDOW
	gWindow = NULL; 
	SDL_Quit();  //Quit SDL
}

void graphics::init() {
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0)
	{
		cout <<"COULD NOT INITIALIZE WINDOW"<<endl;
	}
	else
	{
		gWindow = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if (gWindow == NULL) {
			cout<<"Could not create window"<<endl;
		}
		else{ gScreenSurface = SDL_GetWindowSurface( gWindow);}
	}
}


void graphics::loadMedia() {
	whichSurface[0] = loadSurface("background.bmp");  //Using an array
	whichSurface[1] = loadSurface("bird.bmp"); // of surfaces with the 
	whichSurface[2] = loadSurface("Flappy-Ground.bmp");
	whichSurface[3] = loadSurface("menu.bmp");	
}

SDL_Surface* graphics::loadSurface(string path) {
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str());
	if (loadedSurface == NULL) cout <<"UNABLE TO LOAD SURFACE "<<path<<endl;
	return loadedSurface;
}

void graphics::blitSurface(SDL_Surface* background) {
	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = SCREEN_WIDTH;
	stretchRect.h = SCREEN_HEIGHT;
	
	
	
	
	SDL_BlitScaled(background, NULL, gScreenSurface, &stretchRect);
}


void graphics::animate() {
	bool quit = false;
	int height; int iterator =3;
	while (!quit) {
		height = jack.getHeight(); cout<<height<<endl;// lets get the height of the bird
		blitSurface(whichSurface[0]);      //draw the background
		blitbird(height,75, 75); //draw bird with length and w of 50
		blitground(iterator); //ground
		SDL_UpdateWindowSurface(gWindow);   //BACKGROUND
		checkCrash(height);
		iterator--;
		if (iterator == 0) {
			jack.fall();   //falls one pixel every three loops
			iterator =3;
		}
		while(SDL_PollEvent (&e) != 0) {
			if (e.type == SDL_QUIT) quit = true;
			else if(e.type == SDL_KEYDOWN){
				switch(e.key.keysym.sym) {
				case SDLK_ESCAPE:   //escape quits the gmae
					quit = true;
					break;
				case SDLK_UP:
					jack.jump();  //Ypos goes up!
					break;
				}
			
			}
		}
	}
}

void graphics::blitbird(int yPos, int length, int width) {
	SDL_Rect stretchRect;
	stretchRect.x = SCREEN_WIDTH/2;
	stretchRect.y = yPos;
	stretchRect.w =  length;
	stretchRect.h = width;
	SDL_BlitScaled( whichSurface[1], NULL, gScreenSurface, &stretchRect);
}


void graphics::blitground(int pos) {
	SDL_Rect stretchRect1;  //to get the dimensions of the ground shape
	SDL_Rect stretchRect2; //because it moves
	stretchRect1.x = 0; // starts her
	stretchRect1.y = 4*SCREEN_HEIGHT/5;
	stretchRect1.w = SCREEN_WIDTH*2;
	stretchRect1.h = SCREEN_HEIGHT;
        stretchRect2.x = 4; // starts her
        stretchRect2.y = 4*SCREEN_HEIGHT/5;
        stretchRect2.w = SCREEN_WIDTH*2;
        stretchRect2.h = SCREEN_HEIGHT;
	if (pos == 3) 
		SDL_BlitScaled( whichSurface[2], NULL, gScreenSurface, &stretchRect1);
	else 
		SDL_BlitScaled( whichSurface[2], NULL, gScreenSurface, &stretchRect2);
}

void graphics::checkCrash(int height) {
	if (height  > 344) {
		SDL_Delay(2000);
	}
	else {}
}


void graphics::menu() {
	bool quit = false; bool play = true;
	while (!quit) {
			blitSurface(whichSurface[3]);
			SDL_UpdateWindowSurface(gWindow);   //BACKGROUND
      		while(SDL_PollEvent (&e) != 0) {
                        if (e.type == SDL_QUIT) quit = true;
                        else if(e.type == SDL_KEYDOWN){  //press a key to beign
				 play = true;  //then animate
				quit = true;
			}
		}
	}
	if (play) animate();
}


//void initalFreeze() { 


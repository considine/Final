#include "graphics.h"
#include "bird.h"
#include "pipes.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

using namespace std;

graphics::graphics(int height, int width) {
	QUIT1 = true;
	ufo = false;
	Invisible = false;
	michaelscott = false;
	invincible = false;
	SCREEN_HEIGHT = height;
	SCREEN_WIDTH = width;
	score = 0; // no points yet!
	jack.setInitial(SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/10, SCREEN_WIDTH/10); // sets the inital x and y of the bird "jack"
	jack.setScreen(SCREEN_WIDTH, SCREEN_HEIGHT); // tells the bird the screen dimensions
	bar.setscreen(SCREEN_WIDTH, SCREEN_HEIGHT);
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
	gRenderer = NULL;
	gRenderer = SDL_CreateRenderer( gWindow, 1, SDL_RENDERER_ACCELERATED );	
}


void graphics::loadMedia() {
	whichSurface[0] = loadSurface("background.bmp");  //Using an array
	birdA[0] = loadSurface("bird.bmp"); // of surfaces with the 
	SDL_SetColorKey( birdA[0], SDL_TRUE, SDL_MapRGB( birdA[0]->format, 0, 0, 0 ) );
	
	birdA[1] = loadSurface("birdup.bmp");
	SDL_SetColorKey( birdA[1], SDL_TRUE, SDL_MapRGB( birdA[0]->format, 0, 0, 0 ) );
	birdA[2] = loadSurface("birddown1.bmp");
	SDL_SetColorKey( birdA[2], SDL_TRUE, SDL_MapRGB( birdA[0]->format, 0, 0, 0 ) );
	birdA[3] = loadSurface("birddown5.bmp");
	SDL_SetColorKey( birdA[3], SDL_TRUE, SDL_MapRGB( birdA[0]->format, 0, 0, 0 ) );
	birdA[4] = loadSurface("birddown4.bmp");
	SDL_SetColorKey( birdA[4], SDL_TRUE, SDL_MapRGB( birdA[0]->format, 0, 0, 0 ) );
	birdA[5] = loadSurface("birddown3.bmp");
	SDL_SetColorKey( birdA[5], SDL_TRUE, SDL_MapRGB( birdA[0]->format, 0, 0, 0 ) );
	birdA[6] = loadSurface("ufo.bmp");
	SDL_SetColorKey( birdA[6], SDL_TRUE, SDL_MapRGB( birdA[0]->format, 0, 0, 0 ) );
	birdA[7] = loadSurface("michael.bmp");
	SDL_SetColorKey( birdA[7], SDL_TRUE, SDL_MapRGB( birdA[0]->format, 160, 158, 159 ) );
	
	whichSurface[1] = loadSurface("Flappy-Ground.bmp");
	whichSurface[2] = loadSurface("menu.bmp");	
	whichSurface[3] = loadSurface("pipe.bmp");
	whichSurface[4] = loadSurface("Flappy-Ground-1.bmp");
	whichSurface[5] = loadSurface("Flappy-Ground-2.bmp");
	whichSurface[6] = loadSurface("Space.bmp");
	whichSurface[7] = loadSurface("aliens.bmp");
	whichSurface[8] = loadSurface("words.bmp");
	SDL_SetColorKey( whichSurface[8], SDL_TRUE, SDL_MapRGB( birdA[0]->format, 255, 255, 255 ) );
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
	if (background == whichSurface[8]) stretchRect.h = SCREEN_HEIGHT/5;	
	
	
	
	SDL_BlitScaled(background, NULL, gScreenSurface, &stretchRect);
}


void graphics::animate() {
	bool quit = false;
	int height; int iterator =0; int iterator2=0;
	while (!quit && QUIT1) {
		height = jack.getHeight();// lets get the height of the bird
		if (!ufo) blitSurface(whichSurface[0]);      //draw the background
		else if(ufo&&invincible) blitSurface(whichSurface[7]);
		else blitSurface(whichSurface[6]);
		blitbird(height,50, 50); //draw bird with length and w of 50
		if (!Invisible) drawPipes();
		blitground(iterator2); //ground
		drawSky();
		SDL_UpdateWindowSurface(gWindow);   //BACKGROUND
		if (!invincible) checkCrash(height);  //checks if the bird has crashed
		bar.movetime();
		if ((iterator%2)==0){
			jack.fall();   //falls one pixel every three loops
			iterator = 0;
		}
		iterator++; iterator2++; //for the falling, and the ground movemnent
		while(SDL_PollEvent (&e) != 0) {
			if (e.type == SDL_QUIT) quit = true;
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (jack.getHeight() > 0) jack.jump();
				}
			}
			else if(e.type == SDL_KEYDOWN){
				switch(e.key.keysym.sym) {
				case SDLK_ESCAPE:   //escape quits the gmae
					quit = true;
					break;
					case SDLK_UP:
						bar.changegap(0);
					break;
					case SDLK_DOWN:
						bar.changegap(1);
					break;
					case SDLK_u:
						UFO(); 
					break;
					case SDLK_o:
						off();
					break;
					case SDLK_i:
						Invisible = true;
					break;
					case SDLK_x:
						invincible = true;
					break;
					case SDLK_m:
						michaelscott = true;
					break;
					case SDLK_RIGHT:
						bar.speedup();
					break;	
					case SDLK_LEFT:
						bar.slowdown();
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
	if (michaelscott) {   //compensate for sizes
		stretchRect.w *= 1.5;
		stretchRect.h *= 1.5;
	}
		
		
	if (ufo) SDL_BlitScaled((birdA[6]), NULL, gScreenSurface, &stretchRect);
	else if (michaelscott) SDL_BlitScaled((birdA[7]), NULL, gScreenSurface, &stretchRect);
	else SDL_BlitScaled( birdA[0+jack.getAccelerator()], NULL, gScreenSurface, &stretchRect);
}


void graphics::blitground(int pos) {
	SDL_Rect stretchRect1;  //to get the dimensions of the ground shape
	stretchRect1.x = 0; // starts her
	stretchRect1.y = 4*SCREEN_HEIGHT/5;
	stretchRect1.w = SCREEN_WIDTH*2;
	stretchRect1.h = SCREEN_HEIGHT;
	if (pos%3 == 0){
		SDL_BlitScaled( whichSurface[1], NULL, gScreenSurface, &stretchRect1);
	}
	else {
		SDL_BlitScaled( whichSurface[pos%3+3], NULL, gScreenSurface, &stretchRect1);
		}
}

void graphics::checkCrash(int height) {
	if (height  > 18*SCREEN_HEIGHT/25) {
		lose();
	}
	int tempx;
	int birdprox;//how close the bird is to the pipe
	for (int i=0; i<2; i++) {
		tempx = bar.getx(i) - SCREEN_WIDTH/2;
		if (tempx<31 && tempx > -31) {
			if (bar.gety(i) > jack.getHeight()+bar.getGap()) 
				lose();
			if (bar.gety(i) < jack.getHeight()+jack.getsizeL())
				lose();
		}
	}
	
}


void graphics::menu() {
	bool quit = false; bool play = true;
	initialFreeze();
}


void graphics::initialFreeze() { 
	bool quit = false;
	SDL_Delay(200);
	bool switcher = true; //determines if bird is floating up or down
	int it=0; 
	while(1) {
		SDL_PollEvent (&e);
		if (e.type == SDL_KEYDOWN||e.type == SDL_MOUSEBUTTONDOWN){
			
			jack.jump();
			break;
		}
		it++;
		if (switcher && it%2==0) jack.littlejump() ;
		if (!switcher&& it%2==0)   jack.fall();
		if ((it % 60) == 0 && switcher){ switcher = false;} //start falling
		else if ((it % 60) ==0 && !switcher) {switcher = true;}//start floating
		blitSurface(whichSurface[0]);      //draw the background
		jack.resetSpeed(); //make sure bird is level
                blitbird(jack.getHeight(),50, 50); //draw bird with length and w of 50
		blitSurface(whichSurface[8]);
                blitground(0); //ground
                SDL_UpdateWindowSurface(gWindow);   //BACKGROUND
	}
	jack.accelerate(); //turn on accelerator
	animate();
}

void graphics::drawSky() {
 	SDL_Rect fillRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 32 }; 
	SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x99 );
 	SDL_RenderFillRect( gRenderer, &fillRect );
}

void graphics::drawPipes() {
	int yval; // for double pipage
	for (int num=0; num<2; num++) {
		SDL_Rect stretchRect;
       		yval = bar.gety(num);
		stretchRect.x = bar.getx(num);  //STANDARD PROCEDURE
        	stretchRect.y = yval;		// FOR THE PIPES
        	stretchRect.w =  SCREEN_WIDTH/8;
        	stretchRect.h = SCREEN_HEIGHT;
	
        	SDL_BlitScaled( whichSurface[3], NULL, gScreenSurface, &stretchRect);
		stretchRect.y =0;
		stretchRect.h =yval - bar.getGap();
        	SDL_BlitScaled( whichSurface[3], NULL, gScreenSurface, &stretchRect);
	}
}
	
void graphics::lose() { //when you lose
	off();
	drawPipes();
	SDL_Delay(800);
	QUIT();

}

void graphics::QUIT() {
	QUIT1 = false;
}

void graphics::UFO() {
	ufo = true;
}

void graphics::off() {
	Invisible = false;
	michaelscott = false;
	ufo = false;
	invincible = false;
}

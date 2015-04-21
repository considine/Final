#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL2/SDL.h>  //include the image library
#include <string>
#include "bird.h"
#include "pipes.h"
using namespace std;
class graphics {
	private:
		int SCREEN_HEIGHT;
		int SCREEN_WIDTH;
		SDL_Window* gWindow; // the graphics window
		SDL_Surface* gScreenSurface; //The screen surface
		SDL_Surface* whichSurface[6]; //array of five different surfaces which might be loaded
		SDL_Surface* birdA[6]; //array of five different surfaces which might be loaded
		SDL_Surface* background;
		SDL_Renderer* gRenderer;
		SDL_Event e; //for quitting etc	public:
		int score; //how many pipes have been passed
		bool QUIT1;  //force quit
	public:
		graphics(int = 450, int = 350); //constructor which sets the screen height and width
		~graphics();
		bird jack;
		pipes bar;
		void init(); //initializes window etc, return boolean
		void loadMedia(); //takes an image and loads it
		SDL_Surface* loadSurface(string path);
		void blitSurface(SDL_Surface*); //blits the background image
		void animate();
		void blitbird(int, int, int); //takes length and width and draws bird		
		void blitground(int);
		void checkCrash(int); // sees if the bird has crashed
		void menu(); //displays the menu
		void initialFreeze();
		void drawSky(); //draw the top rectangle
		void drawPipes(); //draws the pipes, takes which pipe 
		void lose();
		void QUIT(); //quits
};
#endif

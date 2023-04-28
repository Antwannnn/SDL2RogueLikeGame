#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include<iostream>
#include<SDL.h>

class Game
{
	
private:

	// Boolean field telling if the game is running or not
	bool bRunning;
	// Pointer to the main window
	SDL_Window* window;
	// Pointer to the main renderer object
	SDL_Renderer* renderer;

public:

	// Constructor
	Game();

	// Destructor
	~Game();

	// This method initializes the main window.
	// title : The title of the window
	// pos_x : horizontal position of the window on the screen
	// pos_y : vertical position of the window on the screen
	// width : width of the window
	// height : height of the window
	// fullscreen : boolean defining whether the window is on fullscreen or not
	void init(const char* title, int pos_x, int pos_y, int width, int height, bool fullscreen);

	// Method rendering the window
	void render();
	// Method cleaning the window
	void clean();
	// Method handling events
	void handleEvent();

	void update();

	void setWindowColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

	// bool method : return false if the window was terminated
	bool running() { return bRunning; }

};

#endif


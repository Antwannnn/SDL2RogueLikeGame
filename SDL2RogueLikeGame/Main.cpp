#include<SDL.h>
#include<stdio.h>
#include"Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->setWindowColor(255, 255, 0, 255);
	game->init("GameScene", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		game->handleEvent();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}
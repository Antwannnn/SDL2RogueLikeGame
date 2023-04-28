#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title, int pos_x, int pos_y, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		std::cout << "Subsytems successfully initialized" << std::endl;
		window = SDL_CreateWindow(title, pos_x, pos_y, width, height, flags);

		if (window)
		{
			if (renderer)
			{
				renderer = SDL_CreateRenderer(window, -1, 0);	
			}
			bRunning = true;
		}
	}
	else
	{
		bRunning = false;
	}

}


void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::handleEvent()
{

	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		bRunning = false;
	}
}

void Game::update()
{
}

void Game::setWindowColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
}

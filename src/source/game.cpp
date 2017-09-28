#include <SDL2/SDL.h>
#include <algorithm>

#include "game.h"
#include "graphics.h"
#include "input.h"

/*
 * holds all information for our main game loop
 */

namespace
{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000/FPS;
}

Game::Game()
{
	// initialize game functions.
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game()
{
}

void Game::gameLoop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->m_player = Player(graphics, 100, 100);

	int LAST_UPDATE_TIME_MS = SDL_GetTicks();

	// start the game loop
	while(true)
	{
		input.beginNewFrame();
		if(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_KEYDOWN :
					if(event.key.repeat == 0)
					{
						input.keyDownEvent(event);
					}
					break;

				case SDL_KEYUP:
					if(event.key.repeat == 0)
					{
						input.keyUpEvent(event);
					}
					break;

				case SDL_QUIT:
					return;
			}
		}

		if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			// Will exit the game loop and thus quit the game.
			return;
		}
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true)
		{
			// Move player to the left.
			this->m_player.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true)
		{
			// Move player to the right.
			this->m_player.moveRight();
		}

		// If neither right or left key is being held, stop player.
		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT))
		{
			this->m_player.stopMoving();
		}


		const int CURRENT_UPDATE_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_UPDATE_TIME_MS - LAST_UPDATE_TIME_MS;

		this->update(std::min(MAX_FRAME_TIME, ELAPSED_TIME_MS));
		LAST_UPDATE_TIME_MS = CURRENT_UPDATE_TIME_MS;

		// draw to screen
		this->draw(graphics);
	}
}

void Game::draw(Graphics &graphics)
{
	// clear any previous content
	graphics.clear();
	this->m_player.draw(graphics);
	graphics.flip();
}

void Game::update(float elapsedTime)
{
	this->m_player.update(elapsedTime);
}



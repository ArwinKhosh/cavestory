#ifndef GAME_H
#define GAME_H

#include "player.h"

class Graphics;

/* Game class
 * has all the game functions
 */

class Game
{
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	Player m_player;
};



#endif // GAME_H

#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "animatedsprite.h"

class graphcis;

class Player : public AnimatedSprite
{
public:
	Player();

	/* Sprite constructor
	 * \param graphics     a Graphics object
	 * \param filePath     a string to sprite location
	 * \param sourceX      where on sprite sheet image start
	 * \param sourceY      where on sprite sheet image start
	 * \param width        width of specific sprite on spritesheet
	 * \param height       height of specific sprite on spritesheet
	 * \param Posx	   	   initial x position of sprite on screen
	 * \param PosY         initial y position of sprite on screen
	 * \param timeToUpdate time to go to next frame
	 */
	Player(Graphics &graphcis, float x, float y);

	/* void draw(Graphics &graphics)
	 * Draws to renderer.
	 */
	void draw(Graphics &graphics);

	/* void update(float elapsedTime);
	 * Updates to the next sprite frame based on time
	 */
	void update(float elapsedTime);

	/* 	void moveLeft();
	 *  Moves the player left by -dx
	 */
	void moveLeft();

	/* 	void moveRight();
	 *  Moves the player right by dx
	 */
	void moveRight();

	/* 	void stopMoving();
	 *  Stops moving the player.
	 */
	void stopMoving();

	virtual void animationDone(std::string currentAnimation) override;
	virtual void setupAnimation() override;

private:
	float m_dx, m_dy;

	Direction m_facing;

};



#endif // PLAYER_H

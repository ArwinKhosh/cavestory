#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <vector>
#include <string>

#include "sprite.h"
#include "globals.h"

/* Animated Sprite class
 * Animates our sprites
 */


class graphics;

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite();

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
	AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
					float posX, float posY, float timeToUpdate);

	/* void play animation
	 * plays animation unless it is already playing
	 */
	void playAnimation(std::string animation, bool once = false);

	/* void update
	 * Updates the animated sprite (timer)
	 */
	void update(int elapsedTime);


	/* void draw
	 * draws sprite to screen
	 */
	void draw(Graphics &graphics, int x, int y);

	/* virtual void setupAnimation
	 * in the end be a purely virtual function for the player class to implement
	 * for now implement in this class
	 * therefore: a required function that sets up all animations for a sprite
	 */
	virtual void setupAnimation();

protected:
	double m_timeToUpdate; 		    // Time between frames.
	bool m_currentAnimationOnce;    // Know that an animation is only being played once.
	std::string m_currentAnimation; // Name of currently playing animation.

	/* void addAnimation
	 * add animation to the list of animations for our sprite
	 * \param frames     number of frames in our animation
	 * \param x			 where on sprite sheet animation starts
	 * \param y 		 where on sprite sheet animation starts
	 * \param name 		 name of aniamtion
	 * \param width		 of each of the frames
	 * \param height     of each of the frames
	 * \param offset     in case each frame is not exactly 16 pixels
	 */
	void addAnimation(std::vector<Vector2> &frames, std::string name, int width, int heigth, Vector2 offset);

	/* void resetAnimation
	 * resets current animation associated with our sprite
	 */
	void resetAnimation();

	/* void stopAnimation
	 * stops current animation
	 */
	void stopAnimation();

	/* void setVisible
	 * sets the visibility of our animation
	 */
	void setVisible(bool visible);

	/* virtual void animationDone
	 * Logic that happens when animation ends
	 */
	virtual void animationDone(std::string currentAnimation);

private:
	std::map<std::string, std::vector<SDL_Rect>> m_animations;
	std::map<std::string, Vector2> m_offsets;

	size_t m_frameIndex;
	double m_timeElapsed;
	bool m_visible;
};


#endif // ANIMATED_SPRITE_H

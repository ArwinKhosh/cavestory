#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>

/* Sprite class
 * Holds all information for individual sprites
 */

class Graphics;

class Sprite
{

public:
	Sprite();

	/* Sprite constructor
	 * \param graphics a Graphics object
	 * \param filePath a string to sprite location
	 * \param sourceX  where on sprite sheet image start
	 * \param sourceY  where on sprite sheet image start
	 * \param width    width of specific sprite on spritesheet
	 * \param height   height of specific sprite on spritesheet
	 * \param Posx	   initial x position of sprite on screen
	 * \param PosY     initial y position of sprite on screen
	 */

	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
			float posX, float posY);

	virtual ~Sprite();

	/* updates the sprite
	 *
	 */
	virtual void update();

	/* draws the sprite to buffer
	 *
	 */
	void draw(Graphics &graphics, int x, int y);

protected:
	SDL_Rect m_sourceRect;
	SDL_Texture* m_spriteSheet;

private:
	float m_x, m_y;
};

#endif //SPRITE_H

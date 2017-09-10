#include "sprite.h"
#include "graphics.h"
#include "globals.h"


Sprite::Sprite()
{

}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
				float posX, float posY) :
						m_x(posX),
						m_y(posY)
{
	this->m_sourceRect.x = sourceX;
	this->m_sourceRect.y = sourceY;
	this->m_sourceRect.w = width;
	this->m_sourceRect.h = height;

	this->m_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if(this->m_spriteSheet == NULL)
		{printf("\nError: Unable to load image\n");}
}

Sprite::~Sprite()
{

}

void Sprite::update()
{

}

void Sprite::draw(Graphics &graphics, int x, int y)
{
	SDL_Rect destinationRect = {x, y, this->m_sourceRect.w * globals::SPRITE_SCALE, this->m_sourceRect.h * globals::SPRITE_SCALE};
	graphics.blitSurface(this->m_spriteSheet, &this->m_sourceRect, &destinationRect);

}



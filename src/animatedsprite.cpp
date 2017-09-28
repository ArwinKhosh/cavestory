#include "animatedsprite.h"
#include "graphics.h"
#include "sprite.h"



AnimatedSprite::AnimatedSprite()
{

}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY, float timeToUpdate) :
				Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
				m_frameIndex(0),
				m_timeElapsed(0),
				m_timeToUpdate(timeToUpdate),
				m_visible(true),
				m_currentAnimationOnce(false),
				m_currentAnimation("")
{

}

//************************************************************
// protected functions
//************************************************************

void AnimatedSprite::addAnimation(std::vector<Vector2> &frames, std::string name, int width, int height, Vector2 offset)
{
	std::vector<SDL_Rect> rectangles;
	for (size_t i = 0; i < frames.size(); ++i)
	{
		SDL_Rect newRect ={frames[i].x * width, frames[i].y * height, width, height};
		rectangles.push_back(newRect);
	}
	this->m_animations.insert(std::pair<std::string, std::vector<SDL_Rect> >(name, rectangles));
	this->m_offsets.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimatedSprite::resetAnimation()
{
	this-> m_animations.clear();
	this-> m_offsets.clear();
}

void AnimatedSprite::stopAnimation()
{
	this->m_frameIndex = 0;
	this->animationDone(this->m_currentAnimation);
}

void AnimatedSprite::setVisible(bool visible)
{
	this->m_visible = visible;
}



//************************************************************
// public functions
//************************************************************

void AnimatedSprite::playAnimation(std::string animation, bool once)
{
	this->m_currentAnimationOnce = once;
	if (this->m_currentAnimation != animation)
	{
		this->m_currentAnimation = animation;
		this->m_frameIndex = 0;
	}
}

void AnimatedSprite::update(int elapsedTime)
{
	this->m_timeElapsed += elapsedTime;
	if (this->m_timeElapsed > this->m_timeToUpdate)
	{
		this->m_timeElapsed -= this->m_timeToUpdate;
		// If we haven't reached the last frame in the current animation.
		if (this->m_frameIndex < this->m_animations[this->m_currentAnimation].size() - 1)
		{
			this->m_frameIndex++;
		}
		else
		{
			// Check if animation is only supposed to play once.
			if (this->m_currentAnimationOnce == true)
			{
				this->setVisible(false);
			}
			// Set frame index back to zero.
			this->m_frameIndex = 0;
			this->animationDone(this->m_currentAnimation);
		}
	}
}

void AnimatedSprite::draw(Graphics &graphics, int x, int y)
{
	if (this->m_visible)
	{
		// Temporary
		SDL_Rect destinationRectangle;
		// Will not change position, but will be drawn in different position
		destinationRectangle.x = x + this->m_offsets[this->m_currentAnimation].x;
		destinationRectangle.y = y + this->m_offsets[this->m_currentAnimation].y;
		destinationRectangle.w = this->m_sourceRect.w * globals::SPRITE_SCALE;
		destinationRectangle.h = this->m_sourceRect.h * globals::SPRITE_SCALE;

		// Get the source rectangle based on current animation and frame
		SDL_Rect sourceRect = this->m_animations[this->m_currentAnimation][this->m_frameIndex];
		graphics.blitSurface(this->m_spriteSheet, &sourceRect, &destinationRectangle);
	}

}


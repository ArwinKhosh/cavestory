#include "player.h"
#include "graphics.h"

namespace player_constants
{
	const float WALK_SPEED = 0.2f;
}

Player::Player() {}

Player::Player(Graphics &graphics, float x, float y) :
	AnimatedSprite(graphics, "dat/sprites/MyChar.png", 0, 0, 16, 16, x, y, 100)
{
	// This is already loaded in Sprite.cpp. Is it useful here?
	graphics.loadImage("dat/sprites/MyChar.png");
	this->setupAnimation();
	this->playAnimation("RunRight");
}

void Player::setupAnimation()
{
	std::vector<Vector2> idleLeftFrames;
	idleLeftFrames.insert(idleLeftFrames.begin(), {Vector2(0, 0)});
	this->addAnimation(idleLeftFrames, "IdleLeft", 16, 16, Vector2(0,0));

	std::vector<Vector2> idleRightFrames;
	idleRightFrames.insert(idleRightFrames.begin(), {Vector2(0, 1)});
	this->addAnimation(idleRightFrames, "IdleRight", 16, 16, Vector2(0,0));

	std::vector<Vector2> runLeftFrames;
	runLeftFrames.insert(runLeftFrames.end(), {Vector2(0, 0), Vector2(1, 0), Vector2(0, 0), Vector2(2, 0)});
	this->addAnimation(runLeftFrames, "RunLeft", 16, 16, Vector2(0,0));

	std::vector<Vector2> runRightFrames;
	runRightFrames.insert(runRightFrames.end(), {Vector2(0, 1), Vector2(1, 1), Vector2(0, 1), Vector2(2, 1)});
	this->addAnimation(runRightFrames, "RunRight", 16, 16, Vector2(0,0));
}

void Player::animationDone(std::string currentAnimation)
{

}

void Player::moveLeft()
{
	this->m_dx = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->m_facing = LEFT;
}

void Player::moveRight()
{
	this->m_dx = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->m_facing = RIGHT;
}


void Player::stopMoving()
{
	this->m_dx = 0.0f;
	this->playAnimation(this->m_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::update(float elapsedTime)
{
	this->m_x += this->m_dx * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics)
{
	AnimatedSprite::draw(graphics, this->m_x, this->m_y);
}





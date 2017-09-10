#include "input.h"

/* Input class
 * keeps track of keyboard states
 */

// This function gets called at the beginning of each new frame
// to reset the keys that are no longer pressed

void Input::beginNewFrame()
{
	this->m_pressedKeys.clear();
	this->m_releasedKeys.clear();
}

// this gets called when a key has been pressed
void Input::keyDownEvent(const SDL_Event& event)
{
	// remember m_pressedKeys is a map. inside brackets is the key
	// which we assign a bool to.

	this->m_pressedKeys[event.key.keysym.scancode] = true;
	this->m_heldKeys[event.key.keysym.scancode] = true;
}

// this gets called when a key is released.
void Input::keyUpEvent(const SDL_Event& event)
{
	this->m_releasedKeys[event.key.keysym.scancode] = true;
	this->m_heldKeys[event.key.keysym.scancode] = false;
}


// was key pressed during the current frame
bool Input::wasKeyPressed(SDL_Scancode key)
{return this->m_pressedKeys[key];}

// check if certain key was released
bool Input::wasKeyReleased(SDL_Scancode key)
{return this->m_releasedKeys[key];}

bool Input::isKeyHeld(SDL_Scancode key)
{return this->m_heldKeys[key];}






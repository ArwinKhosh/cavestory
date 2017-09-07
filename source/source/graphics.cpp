
#include<SDL2/SDL.h>

#include "graphics.h"

Graphics::Graphics()
{
	// the third and fourt argument want a pointer to the window and renderer object
	//they are alreade pointer, need to make a pointer to a pointer.
	// do that by taking the address of object. could have also written &m_object
	// remember: this->m_window is the same as (*this).m_window. just dereferencing
	// the pointer to the object then access members
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->m_window, &this->m_renderer);
	SDL_SetWindowTitle(this->m_window,"Cavestory");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->m_window);
}

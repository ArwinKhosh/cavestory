
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"
#include "globals.h"

Graphics::Graphics()
{
	// the third and fourt argument want a pointer to the window and renderer object
	//they are alreade pointer, need to make a pointer to a pointer.
	// do that by taking the address of object. could have also written &m_object
	// remember: this->m_window is the same as (*this).m_window. just dereferencing
	// the pointer to the object then access members
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGTH, 0, &this->m_window, &this->m_renderer);
	SDL_SetWindowTitle(this->m_window,"Cavestory");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->m_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath)
{
	// check if the image has been loaded before
	if (this->m_spriteSheets.count(filePath) == 0)
	{
		//RHS function wants a char* as input, not a std:string
		// use c_str to convert
		this->m_spriteSheets[filePath] =IMG_Load(filePath.c_str());
	}
	return this->m_spriteSheets[filePath];
}


void Graphics::blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(this->m_renderer, source, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->m_renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->m_renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return this->m_renderer;
}



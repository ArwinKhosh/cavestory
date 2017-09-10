#ifndef GRAPHICS_H
#define GRAHPICS_H



/* Graphics class
 * has all the graphis functions
 */

#include <string>
#include <map>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {

public:
	Graphics();
	~Graphics();


	/* SDL_Surface* loadimage
	 * Load image into m_spriteSHeets map if it does not already exist
	 * as a result each image will only ever be loaded once
	 * Returns the image from the map regardless of whetheror not it was just laoded
	 */
	SDL_Surface* loadImage(const std::string &filePath);

	/* void blitSurface
	 * Draws a texture to a certain part of the screen
	 */
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/* void flip
	 * Renders everything to the screen
	 */
	void flip();

	/* void clear
	 * clears the screen
	 */
	void clear();

	/* SDL_Renderer* getRenderer
	 * Returns the renderer
	 */
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	// hold in memory every sprite sheet such that we do not need to constantly
	// load images which can make program slow.
	std::map<std::string, SDL_Surface*> m_spriteSheets;
};





#endif //GRAHPICS_H

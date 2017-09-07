#ifndef GRAPHICS_H
#define GRAHPICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {

public:
	Graphics();
	~Graphics();
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};





#endif //GRAHPICS_H

#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game
{
public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	bool m_turn;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	SDL_Texture* m_pTexture;
	// 원본 사각형
	SDL_Rect m_sourceRectangle;
	// 대상 사각형
	SDL_Rect m_destinationRectangle;

	SDL_Texture* m_pDogge;

	SDL_Rect m_sourceRectangle1;
	// 대상 사각형
	SDL_Rect m_destinationRectangle1;

};

#endif /* defined(__Game__) */
#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include <time.h>
#include <stdio.h>


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
	void randpuzzle();
	void keyPad();
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

private: 
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	bool m_turn;

	int Puzzle_X[9] = { 50, 233, 416, 50, 233, 416, 50, 233, 416};
	int Puzzle_y[9] = { 50, 50, 50, 233, 233, 233, 416, 416, 416};
	int Puzzle_i[9] = {0,1,2,3,4,5,6,7,8};

	int move_x = 0;
	int move_y = 0;

	int m_currentFrame;
	int m_currentFrame_1;
	int m_currentFrame_2;

	int m_currentRow_2 = 0;
};

#endif /* defined(__Game__) */
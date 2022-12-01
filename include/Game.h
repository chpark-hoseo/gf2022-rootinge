#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include "TextureManager.h"
#include "Player.h"
#include "GameObject.h"

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

	void quit() { m_bRunning = false; }

	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	void randpuzzle();
	void keyPad(){}
	void blockswitch();
	void switchcode(int innum);


	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

private: 
	static Game* s_pInstance;
	std::vector<GameObject*> m_gameObjects;

	

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	bool m_turn;


	int puzzle_x[9] = { 50, 233, 416, 50, 233, 416, 50, 233, 416};
	int puzzle_y[9] = { 50, 50, 50, 233, 233, 233, 416, 416, 416};
	int puzzle_i[9] = {0,1,2,3,4,5,6,7,8};

	int move_x = 0;
	int move_y = 0;

	int m_currentFrame;
	int m_currentFrame_1;
	int m_currentFrame_2;


	int m_currentRow_2 = 1;
};
typedef Game TheGame;
#endif /* defined(__Game__) */
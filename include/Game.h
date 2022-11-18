#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <algorithm>
#include <vector>
#include <functional>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"

class Game
{
public:
	Game() { }
	~Game() { }

	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

	void quit() { m_bRunning = false; }

private: 
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	bool m_turn;


	std::vector<GameObject*> m_gameObjects;

	int m_currentFrame;
	int m_currentFrame_1;
	int m_currentFrame_2;

	int m_currentRow_2 = 0;

	static Game* s_pInstance; // ���� ������� 
};

typedef Game TheGame;

#endif /* defined(__Game__) */
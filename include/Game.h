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
#include "Puzzle.h"
#include "GameManager.h"
#include "Clear.h"


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




private: 
	static Game* s_pInstance;

	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*> m_gameClear;

	

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};
typedef Game TheGame;
#endif /* defined(__Game__) */
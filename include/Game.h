#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameObject.h"
#include "Player.h"
#include "Monster.h"

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

	GameObject m_go;
	Player m_player;
	Monster m_monster;
	Monster m_monster_1;


	int m_currentFrame;
	int m_currentFrame_1;
	int m_currentFrame_2;

	int m_currentRow_2 = 0;
};

#endif /* defined(__Game__) */
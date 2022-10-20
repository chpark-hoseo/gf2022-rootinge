#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include "Enemy.h"
#include "Vector.h"

static int Enemynum = -1;
static int is_x[100];
static int is_y[100];

class Game
{
private:
	Vector m_Vector;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	EnemySystem m_EnemySystem;
	bool m_bRunning;

public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running();
	void handleEvents();
	void clean();

};


#endif /* defined(__Game__) */
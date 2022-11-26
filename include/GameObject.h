#pragma once
#include<iostream>
#include <SDL2/SDL.h>
#include "GameObject.h"
#include "Player.h"

class GameObject {

public:
	void load(int x, int y, int width, int height, std::string textureID);

	void draw(SDL_Renderer* pRenderer);
	void update();

	void clean();

protected:
	std::string m_textureID;

	GameObject m_go;
	Player m_player;

	int m_x;
	int m_y;
	int m_width;
	int m_height;

	int m_currentFrame;
	int m_currentRow;
};

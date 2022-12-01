#include "Clear.h"
#include "InputHandler.h"
#include "GameManager.h"

Clear::Clear(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Clear::draw()
{
	if (blink != 0){
	SDLGameObject::draw(); 
	}
}


void Clear::update()
{
	handleInput();
	blink = ((SDL_GetTicks() / 300) % 3);
}

void Clear::clean(){}

void Clear::handleInput()
{
	SDL_ShowCursor(true);
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	if (vec->getX() >= 240 && vec->getX() <= 440 && vec->getY() >= 165 && vec->getY() <= 262)
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			TheGameManager::Instance()->m_stage = 1;
			TheGameManager::Instance()->m_clear = 0;
		}
	}
	else if (vec->getX() >= 70 && vec->getX() <= 170 && vec->getY() >= 490 && vec->getY() <= 590)
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			SDL_Quit();
		}
	}
	
}
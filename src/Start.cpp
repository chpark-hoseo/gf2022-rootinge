#include "Start.h"
#include "InputHandler.h"
#include "GameManager.h"

Start::Start(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Start::draw()
{
	SDLGameObject::draw();
}


void Start::update()
{
	handleInput();
}

void Start::clean() {}

void Start::handleInput()
{
	SDL_ShowCursor(true);
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();

	if (vec->getX() >= 0 && vec->getX() <= 640 && vec->getY() >= 0 && vec->getY() <= 640)
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			TheGameManager::Instance()->m_stage = 0;
		}
	}
	
	

}
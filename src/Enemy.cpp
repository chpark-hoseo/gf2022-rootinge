#include "Enemy.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
    handleInput();
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    SDLGameObject::update();
}


void Enemy::handleInput()
{
    if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
        printf("shoot \n");
    }
    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    
    m_velocity = (*vec - m_position - Vector2D(64, 41)) / 100;

}

void Enemy::clean() {}
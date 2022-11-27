#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
	SDLGameObject::draw();
}


void Player::update()
{
    handleInput();
    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
    SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        if (m_position.getX() >= 590)
        {
            m_velocity.setX(0);
        }
        else
        {
            m_velocity.setX(4);
        }
        m_currentRow = 1;
    }
    else
    {
        m_velocity.setX(0);
        m_velocity.setY(0);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        if (m_position.getX() <= 0)
        {
            m_velocity.setX(0);
        }
        else
        {
            m_velocity.setX(-4);
        }
        m_currentRow = 0;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        if (m_position.getY() <= 0)
        {
            m_velocity.setY(0);
        }
        else
        {
            m_velocity.setY(-4);
        }
        m_currentRow = 2;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {

        if (m_position.getY() >= 590)
        {
            m_velocity.setY(0);
        }
        else
        {
            m_velocity.setY(4);
        }
        m_currentRow = 3;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)){
        // blockswitch();
    }

}


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
    wallchange();
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    SDLGameObject::update();
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_velocity.setX(2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
        m_velocity.setX(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
        m_velocity.setY(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
        m_velocity.setY(2);
    }
}

void Player::wallchange()
{
    if(m_position.getX() <= 0 || m_position.getX() + 128 >= 480)
        m_velocity.setX(m_velocity.getX() * -1);

    if (m_position.getY() <= 0 || m_position.getY() + 82 >= 640)
        m_velocity.setY(m_velocity.getY() * -1);
}

void Player::clean() {}
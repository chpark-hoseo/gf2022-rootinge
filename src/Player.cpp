#include "Player.h"
#include "InputHandler.h"
#include "Game.h"

int Player::Palyer_X;
int Player::Palyer_Y;

int Player::Player_currentFrame;
int Player::Player_currentRow;

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}


void Player::draw()
{
	SDLGameObject::draw();
}


void Player::update()
{
    Palyer_X = m_position.getX();
    Palyer_Y = m_position.getY();
    handleInput();
    m_currentFrame = ((SDL_GetTicks() / 100) % 5);
    Player_currentFrame = m_currentFrame;
    Player_currentRow = m_currentRow;
    SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput()
{
    SDL_ShowCursor(false);

    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    m_velocity = (*vec - m_position - Vector2D(25, 25)) / 1;
    printf("%d\n", vec->getX());
    if (m_velocity.getX() < 0)
    {
        m_currentRow = 0;
    }
    else if (m_velocity.getX() > 0)
    {
        m_currentRow = 1;
    }

    if (0 > m_velocity.getY() && abs(m_velocity.getY()) > abs(m_velocity.getX()))
    {
        m_currentRow = 2;
    }
    else if (0 < m_velocity.getY() && abs(m_velocity.getY()) > abs(m_velocity.getX()))
    {
        m_currentRow = 3;
    }
}
   


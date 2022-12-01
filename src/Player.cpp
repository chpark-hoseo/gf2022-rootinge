#include "Player.h"
#include "InputHandler.h"
#include "Game.h"

int Player::Palyer_X;
int Player::Palyer_Y;

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
    SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput()
{
    /*  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
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

          TheGame::Instance()->blockswitch();
      }*/

    if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
        printf("shoot \n");
        TheGame::Instance()->blockswitch();
    }
    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    m_velocity = (*vec - m_position - Vector2D(25, 25)) / 1;
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
   


#include "Monster.h"

void Monster::update(int moveSpeed)
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    if (m_x < 0)
        m_turn = false;
    else if (m_x > 480 - m_width)
        m_turn = true;

    if (m_turn)
        m_x -= moveSpeed;
    else
        m_x += moveSpeed;
    
}
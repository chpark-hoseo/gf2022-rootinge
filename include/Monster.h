#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
    Monster(int movespeed)
    {
        m_move = movespeed;
    }
    void update();

private:
    int m_move;
    bool m_turn = false;
};
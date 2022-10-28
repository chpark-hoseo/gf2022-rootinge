#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
    void update(int moveSpeed);

private:
    bool m_turn;
};
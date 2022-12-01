#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
    static int Palyer_X;
    static int Palyer_Y;

    float getX() { return m_position.getX(); }
    float getY() { return m_position.getY(); }

    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();

};

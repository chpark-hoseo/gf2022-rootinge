#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
    static int Palyer_X;
    static int Palyer_Y;

    static int Player_currentFrame;
    static int Player_currentRow;

    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();

};

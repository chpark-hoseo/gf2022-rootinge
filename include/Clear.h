#pragma once
#include "SDLGameObject.h"

class Clear : public SDLGameObject
{
public:


    Clear(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();

private:
    int blink = 0;

};
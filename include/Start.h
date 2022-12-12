#pragma once
#include "SDLGameObject.h"

class Start : public SDLGameObject
{
public:


    Start(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void handleInput();

private:
    int blink = 0;

}; 
#pragma once

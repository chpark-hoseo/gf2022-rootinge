#pragma once
#include "SDLGameObject.h"
#include "Player.h"
class Puzzle : public SDLGameObject {
public:
    Puzzle(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    void switchcode(int innum);

private:

};

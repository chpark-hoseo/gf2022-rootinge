#pragma once
#include "SDLGameObject.h"



class Piece : public SDLGameObject {
public:
    Piece(const LoaderParams* pParams, int x,int y, int i);
    virtual void draw();
    virtual void update();
    virtual void clean() {}

private:


    int seat_x;
    int seat_y;
    int seat_i;
};

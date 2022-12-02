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
    void randpuzzle();
    void blockswitch();
    void handleInput();
    void gameClear();
    void swutchpuzzle();
private:
    int puzzle_x[9] = { 50, 233, 416, 50, 233, 416, 50, 233, 416};
    int puzzle_y[9] = { 50, 50, 50, 233, 233, 233, 416, 416, 416};
    int puzzle_i[9] = { 0,1,2,3,4,5,6,7,8 };
    int direction;
    bool clickpuzzle = false;
    int movenum_1;
    int movenum_2;
    int save;
    int movespeed = 15;
};

#pragma once
#include "SDLGameObject.h"
#include "Player.h"
#include <vector>

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

    static int puzzle_x[9];
    static int puzzle_y[9];
    static int puzzle_i[9];
private:


    int direction;
    bool clickpuzzle = false;
    int movenum_1;
    int movenum_2;
    int save;
    int movespeed = 15;

    std::vector<GameObject*> m_piece;
};

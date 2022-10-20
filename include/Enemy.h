#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include "Vector.h"
#include "TextureManager.h"


#define normalize() srand(time(0))
#define MAX_ENEMY  512




//class Enemy {
//
//public:
//    bool IsLive;
//
//    Vector Pos;
//    Vector Des;
//
//    Enemy* prev;
//};

typedef struct Enemy
{

    bool IsLive;

    Vector Pos;
    Vector Des;

    Enemy* prev;

};


class EnemySystem {


public:

    int Delay;

    Enemy root;
    Enemy tail;
    /*static EnemySystem* Instance()
    {
        if (s_pInstance1 == 0)
            s_pInstance1 = new EnemySystem();
        return s_pInstance1;
    }*/

    void InitEnemySystem();

    void ProcessEnemy();

    void NewEnemy();

    

private:
//    static EnemySystem* s_pInstance1;

    Vector m_Vector;
    
};


static EnemySystem ES;
static Enemy Ene[MAX_ENEMY];
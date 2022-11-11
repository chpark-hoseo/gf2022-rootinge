#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "LoaderParams.h"

class GameObject {
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    virtual ~GameObject() {}

protected:
    GameObject(const LoaderParams* pParams) { }
};

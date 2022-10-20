#pragma once
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>

class TextureManager {

private:
    TextureManager() {}

    static TextureManager* s_pInstance;

    std::map<std::string, SDL_Texture*> m_textureMap;

public:
    ~TextureManager() {}

    static TextureManager* Instance()
    {
        if (s_pInstance == 0)
            s_pInstance = new TextureManager();
        return s_pInstance;
    }
    
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
     
    void draw(std::string id, int x, int y, int width, int height,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height,
        int currentRow, int currentFrame,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);


};
typedef TextureManager TheTextureManager;
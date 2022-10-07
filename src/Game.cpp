#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
               SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255); // 붉은색 배경

            }
            else {
                return false; // 랜더러 생성 실패
            }
        }
        else {
            return false; // 윈도우 생설 실패 l
        }
    }
    else {
        return false; // SDL 초기화 실패
    }
    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;

    m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);

    m_textureManager.load("assets/pngegg.png", "pngegg", m_pRenderer);

    m_bRunning = true;
    m_turn = true;

    return true;
    
}

void Game::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    m_currentFrame_1 = ((SDL_GetTicks() / 100) % 8);
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);

    m_textureManager.drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

    m_textureManager.drawFrame("pngegg", 200, 200, 67, 72, 0, m_currentFrame_1, m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) //이벤트가 진행되는동안 확인하기 위해?
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::clean()
{

    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}


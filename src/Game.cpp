#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
               SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255); // ������ ���

            }
            else {
                return false; // ������ ���� ����
            }
        }
        else {
            return false; // ������ ���� ���� l
        }
    }
    else {
        return false; // SDL �ʱ�ȭ ����
    }
    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;

    if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }
   
    if (!TheTextureManager::Instance()->load("assets/pngegg.png", "pngegg", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->load("assets/player_1.png", "player_1", m_pRenderer))
    {
        return false;
    }



    m_bRunning = true;
    m_turn = false;

    return true;
    
}

void Game::update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
    m_currentFrame_1 = ((SDL_GetTicks() / 100) % 8);

    
    m_currentFrame_2 = ((SDL_GetTicks() / 100) % 5);
    if (m_currentFrame_2 == 4 && m_turn)
    {
        m_turn = false;
        m_currentRow_2++;
        if (m_currentRow_2 == 4)
        {
            m_currentRow_2 = 0;
        }
    }
    else if (m_currentFrame_2 == 0)
    {
        m_turn = true;
    }
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

    TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

    TheTextureManager::Instance()->drawFrame("pngegg", 200, 200, 67, 72, 0, m_currentFrame_1, m_pRenderer);

    TheTextureManager::Instance()->drawFrame("player_1", 300, 300, 50, 50, m_currentRow_2, m_currentFrame_2, m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) //�̺�Ʈ�� ����Ǵµ��� Ȯ���ϱ� ����?
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


#include "Game.h"



bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
               SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255); // ������ ���

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


    /*if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }*/
   
    if (!TheTextureManager::Instance()->load("Assets/circle.png", "circle", m_pRenderer))
    {
        return false;
    }
    m_EnemySystem.InitEnemySystem();
    normalize();
    
    m_bRunning = true;
    

    return true;
    
}

void Game::update()
{
    m_EnemySystem.ProcessEnemy();
    for (int i = 0; i < Enemynum; i++)
    {
        TheTextureManager::Instance()->draw("circle", is_x[i], is_y[i], 50, 50, m_pRenderer);
    }
    Enemynum = 0;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

 //   TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
 //   TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
    //TheTextureManager::Instance()->draw("circle", 0, 0, 50, 50, m_pRenderer);


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

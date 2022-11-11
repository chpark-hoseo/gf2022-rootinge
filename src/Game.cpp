#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
               SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 0, 255); // 붉은색 배경

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


    if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
    {
        return false;
    }
    
   
   
    m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
    m_gameObjects.push_back(new Enemy(new LoaderParams(100, 100, 128, 82, "animate")));

    

    m_bRunning = true;
    m_turn = false;

    return true;
    
}

void Game::update()
{
    std::for_each(m_gameObjects.begin(), m_gameObjects.end(), std::mem_fun(&GameObject::update));

   /* for (int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }*/
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    //std::for_each(m_gameObjects.begin(), m_gameObjects.end(), std::mem_fun(&GameObject::draw));
    for (int i = 0; i != m_gameObjects.size(); i++) {
        m_gameObjects[i]->draw();
    }
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


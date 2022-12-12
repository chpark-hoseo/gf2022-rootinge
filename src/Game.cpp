#include "Game.h"
#include "InputHandler.h"
#include "GameManager.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
               //SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 0, 255); // 붉은색 배경

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

   
 
    
    if (!TheTextureManager::Instance()->loadkey("assets/player4.dib", "player", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->loadkey("assets/player5.dib", "player_1", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->loadkey("assets/flower.png", "flower", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->loadkey("assets/next.png", "next", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->loadkey("assets/exit1.png", "exit", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->loadkey("assets/clear.png", "clear", m_pRenderer))
    {
        return false;
    }

    if (!TheTextureManager::Instance()->loadkey("assets/sliding.png", "sliding", m_pRenderer))
    {
        return false;
    }
    if (!TheTextureManager::Instance()->loadkey("assets/touch.png", "touch", m_pRenderer))
    {
        return false;
    }

    m_gamePlay0.push_back(new Start(new LoaderParams(124, 100, 391, 221, "sliding")));
    m_gamePlay0.push_back(new Clear(new LoaderParams(220, 400, 200, 24, "touch")));

    m_gamePlay1.push_back(new Puzzle(new LoaderParams(50, 50, 550, 550, "flower")));
    m_gamePlay1.push_back(new Player(new LoaderParams(0, 0, 50, 50, "player")));

    m_gamePlay2.push_back(new Puzzle(new LoaderParams(50, 50, 550, 550, "player_1")));
    m_gamePlay2.push_back(new Player(new LoaderParams(0, 0, 50, 50, "player")));

    m_gameClear.push_back(new Clear(new LoaderParams(240, 165, 200, 97, "next")));
    m_gameClear.push_back(new Clear(new LoaderParams(70, 490, 100, 100, "exit")));

    m_gameClear1.push_back(new Clear(new LoaderParams(230, 165, 200, 43, "clear")));
    m_gameClear1.push_back(new Clear(new LoaderParams(70, 490, 100, 100, "exit")));

    m_bRunning = true;
    return true;
    
}

void Game::update()
{

    if (TheGameManager::Instance()->m_clear == 1)
    {
        for (int i = 0; i < m_gameClear.size(); i++)
        {
            m_gameClear[i]->update();
        }
    }
    else if (TheGameManager::Instance()->m_clear == 2)
    {
        for (int i = 0; i < m_gameClear1.size(); i++)
        {
            m_gameClear1[i]->update();
        }
    }
    else if (TheGameManager::Instance()->m_stage == 0)
    {
        for (int i = 0; i < m_gamePlay1.size(); i++)
        {
            m_gamePlay1[i]->update();
        }
    }
    
    else if (TheGameManager::Instance()->m_stage == 1)
    {
        for (int i = 0; i < m_gamePlay2.size(); i++)
        {
            m_gamePlay2[i]->update();
        }
    }
    else if (TheGameManager::Instance()->m_stage == -1)
    {
        for (int i = 0; i < m_gamePlay0.size(); i++)
        {
            m_gamePlay0[i]->update();
        }
    }

    SDL_Delay(10);
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    if (TheGameManager::Instance()->m_stage == -1)
    {
        for (int i = 0; i < m_gamePlay0.size(); i++)
        {
            m_gamePlay0[i]->draw();
        }
    }
    else if (TheGameManager::Instance()->m_stage == 0)
    {
        for (int i = 0; i != m_gamePlay1.size(); i++) {
            m_gamePlay1[i]->draw();
        }
    }
    else if (TheGameManager::Instance()->m_stage == 1)
    {
        for (int i = 0; i != m_gamePlay1.size(); i++) {
            m_gamePlay2[i]->draw();
        }
    }

    if (TheGameManager::Instance()->m_clear == 1)
    {
        for (int i = 0; i != m_gameClear.size(); i++) {
            m_gameClear[i]->draw();
        }
    }
    else if (TheGameManager::Instance()->m_clear == 2)
    {
        for (int i = 0; i != m_gameClear1.size(); i++) {
            m_gameClear1[i]->draw();
        }
    }
    
    SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
    return m_bRunning;
}

void Game::handleEvents()
{
    
    TheInputHandler::Instance()->update();
}

void Game::clean()
{
    TheInputHandler::Instance()->clean();

    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
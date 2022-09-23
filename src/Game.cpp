#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        m_pWindow = SDL_CreateWindow(
            title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                /*SDL_SetRenderDrawColor(
                    m_pRenderer, 255, 255, 255, 255);*/

                SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");

                m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

                SDL_FreeSurface(pTempSurface);
                // 원본상자의 너비/높이 설정
                SDL_QueryTexture(m_pTexture, NULL, NULL,
                    &m_sourceRectangle.w, &m_sourceRectangle.h);
                // 대상상자의 너비/높이 설정
                m_destinationRectangle.w = m_sourceRectangle.w;
                m_destinationRectangle.h = m_sourceRectangle.h;
                //원본상자/대상상자의 위치 설정
                m_destinationRectangle.x = m_sourceRectangle.x = 0;
                m_destinationRectangle.y = m_sourceRectangle.y = 0;


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

    m_bRunning = true;
    return true;
}

void Game::update()
{

}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
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


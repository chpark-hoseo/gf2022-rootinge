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

    SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");

    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);
    // 원본상자의 너비/높이 설정
    SDL_QueryTexture(m_pTexture, NULL, NULL,
        &m_sourceRectangle.w, &m_sourceRectangle.h);
    // 대상상자의 너비/높이 설정

    //원본상자
    //m_sourceRectangle.w = 50;
    //m_sourceRectangle.h = 50;
    //대상상자
    m_destinationRectangle.w = width;
    m_destinationRectangle.h = height;


    //원본상자/대상상자의 위치 설정
    m_sourceRectangle.x = 0;
    m_sourceRectangle.y = 0;

    m_destinationRectangle.x = 0;
    m_destinationRectangle.y = 0;

    m_bRunning = true;
    m_turn = true;

    return true;
}

void Game::update()
{
    //// 반복 운동
    //if (m_turn)
    //{
    //    m_destinationRectangle.x += 1;
    //    SDL_Delay(10);
    //    if (m_destinationRectangle.x > 480 - m_sourceRectangle.w)
    //        m_turn = false;
    //}
    //else
    //{
    //    m_destinationRectangle.x -= 1;
    //    SDL_Delay(10);
    //    if (m_destinationRectangle.x < 0)
    //        m_turn = true;
    //}
    
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
    SDL_DestroyTexture(m_pTexture); // 추가
    SDL_DestroyTexture(m_pDogge);
    SDL_Quit();
}


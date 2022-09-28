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
    m_bRunning = true;
    m_turn = true;

    SDL_Surface* pDogge = IMG_Load("assets/Dogge.png");

    m_pDogge = SDL_CreateTextureFromSurface(m_pRenderer, pDogge);

    SDL_FreeSurface(pDogge);

    SDL_QueryTexture(m_pDogge, NULL, NULL, &m_sourceRectangle1.w, &m_sourceRectangle1.h);

    m_destinationRectangle1.w = m_sourceRectangle1.w * 6;
    m_destinationRectangle1.h = m_sourceRectangle1.h * 6;
    //원본상자/대상상자의 위치 설정
    m_destinationRectangle1.x = m_sourceRectangle1.x = 0;
    m_destinationRectangle1.y = m_sourceRectangle1.y = 0;
    m_destinationRectangle1.x = 240 - m_destinationRectangle1.w/2;
    m_destinationRectangle1.y = 320 - m_destinationRectangle1.h/2;



    return true;
}

void Game::update()
{
    // 반복 운동
    if (m_turn)
    {
        m_destinationRectangle.x += 1;
        SDL_Delay(10);
        if (m_destinationRectangle.x > 480 - m_sourceRectangle.w)
            m_turn = false;
    }
    else
    {
        m_destinationRectangle.x -= 1;
        SDL_Delay(10);
        if (m_destinationRectangle.x < 0)
            m_turn = true;
    }
}

void Game::render()
{
   /* SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pDogge, &m_sourceRectangle1, &m_destinationRectangle1);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderPresent(m_pRenderer);*/

    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(m_pRenderer);

    SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
    SDL_RenderFillRect(m_pRenderer, &fillRect);

    SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
    SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(m_pRenderer, &outlineRect);

    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
    SDL_RenderDrawLine(m_pRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 0, 255);
    for (int i = 0; i < SCREEN_HEIGHT; i += 4)
    {
        SDL_RenderDrawPoint(m_pRenderer, SCREEN_WIDTH / 2, i);
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
    SDL_DestroyTexture(m_pTexture); // 추가
    SDL_DestroyTexture(m_pDogge);
    SDL_Quit();
}


#include "Game.h"

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

    srand(time(NULL));
    randpuzzle();

    m_bRunning = true;
    m_turn = false;

    return true;
    
}

void Game::update()
{
    m_currentFrame_2 = ((SDL_GetTicks() / 100) % 5);
    keyPad();

    
    
    /*if (m_currentFrame_2 == 4 && m_turn)
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
    }*/
    SDL_Delay(10);
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    TheTextureManager::Instance()->drawFrame("player_1", Puzzle_X[Puzzle_i[0]], Puzzle_y[Puzzle_i[0]], 183, 183, m_currentRow_2 * 3 + 0, m_currentFrame_2 * 3 + 0, m_pRenderer); // 0,0
    TheTextureManager::Instance()->drawFrame("player_1", Puzzle_X[Puzzle_i[1]], Puzzle_y[Puzzle_i[1]], 183, 183, m_currentRow_2 * 3 + 0, m_currentFrame_2 * 3 + 1, m_pRenderer); // 0,1
    TheTextureManager::Instance()->drawFrame("player_1", Puzzle_X[Puzzle_i[2]], Puzzle_y[Puzzle_i[2]], 183, 183, m_currentRow_2 * 3 + 0, m_currentFrame_2 * 3 + 2, m_pRenderer); // 0,2

    TheTextureManager::Instance()->drawFrame("player_1", Puzzle_X[Puzzle_i[3]], Puzzle_y[Puzzle_i[3]], 183, 183, m_currentRow_2 * 3 + 1, m_currentFrame_2 * 3 + 0, m_pRenderer); // 1,0
    TheTextureManager::Instance()->drawFrame("player_1", Puzzle_X[Puzzle_i[4]], Puzzle_y[Puzzle_i[4]], 183, 183, m_currentRow_2 * 3 + 1, m_currentFrame_2 * 3 + 1, m_pRenderer); // 1,1
    TheTextureManager::Instance()->drawFrame("player_1", Puzzle_X[Puzzle_i[5]], Puzzle_y[Puzzle_i[5]], 183, 183, m_currentRow_2 * 3 + 1, m_currentFrame_2 * 3 + 2, m_pRenderer); // 1,2

    TheTextureManager::Instance()->drawFrame("player_1", Puzzle_X[Puzzle_i[6]], Puzzle_y[Puzzle_i[6]], 183, 183, m_currentRow_2 * 3 + 2, m_currentFrame_2 * 3 + 0, m_pRenderer); // 2,0
    TheTextureManager::Instance()->drawFrame("player_1", Puzzle_X[Puzzle_i[7]], Puzzle_y[Puzzle_i[7]], 183, 183, m_currentRow_2 * 3 + 2, m_currentFrame_2 * 3 + 1, m_pRenderer); // 2,1

    TheTextureManager::Instance()->drawFrame("player", move_x, move_y, 50, 50, m_currentRow_2, m_currentFrame_2, m_pRenderer);

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

void Game::randpuzzle() 
{
    int tmp;
    int count = 0;
    int isSame = 0;
    while (count < 9) 
    {
        isSame = 0;
        tmp = rand() % 9;

        for (int i = 0; i < count; i++) { //중복검사
            if (tmp == Puzzle_i[i]) { //중복이 있을때
                isSame = 1;
                break;
            }
        }
        if (isSame == 0) { //중복없음
            Puzzle_i[count] = tmp;
            count++;
        }
    }
}

void Game::keyPad()
{
    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        if (move_x <= 0)
        {
            move_x -= 0;
        }
        else
        {
            move_x -= 4;
        }
        m_currentRow_2 = 0;
    }
    if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        if (move_x >= 590)
        {
            move_x += 0;
        }
        else
        {
            move_x += 4;
        }
        m_currentRow_2 = 1;
    }
    if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
        if (move_y >= 590)
        {
            move_y += 0;
        }
        else
        {
            move_y += 4;
        }
        m_currentRow_2 = 3;
    }
    if (currentKeyStates[SDL_SCANCODE_UP])
    {
        if (move_y <= 0)
        {
            move_y += 0;
        }
        else
        {
            move_y -= 4;
        }
        m_currentRow_2 = 2;
    }
}
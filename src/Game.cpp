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

    // ��
    {
        SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");

        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

        SDL_FreeSurface(pTempSurface);


        // �������� �ʺ�/���� ����
        m_sourceRectangle.w = 128;
        m_sourceRectangle.h = 82;
        m_destinationRectangle.w = m_sourceRectangle.w;
        m_destinationRectangle.h = m_sourceRectangle.h;

        //��������/�������� ��ġ ����
        m_destinationRectangle.x = m_sourceRectangle.x = 0;
        m_destinationRectangle.y = m_sourceRectangle.y = 0;
    }

    // ��2
    {
        SDL_Surface* pTempSurface_1 = SDL_LoadBMP("assets/animate.bmp");

        m_pTexture_1 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface_1);

        SDL_FreeSurface(pTempSurface_1);


        // �������� �ʺ�/���� ����
        m_sourceRectangle_1.w = 128;
        m_sourceRectangle_1.h = 82;
        m_destinationRectangle_1.w = m_sourceRectangle_1.w;
        m_destinationRectangle_1.h = m_sourceRectangle_1.h;

        //��������/�������� ��ġ ����
        m_destinationRectangle_1.x = m_sourceRectangle_1.x = 0;
        m_destinationRectangle_1.y = m_sourceRectangle_1.y = 0;
        m_destinationRectangle_1.y = 82;
    }
    // Ŀ��
    {
        SDL_Surface* pTempSurface1 = IMG_Load("assets/pngegg.png");

        m_pugegg = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface1);

        SDL_FreeSurface(pTempSurface1);


        // �������� �ʺ�/���� ����
        m_sourceRectangle1.w = 67;
        m_sourceRectangle1.h = 72;
        m_destinationRectangle1.w = m_sourceRectangle1.w;
        m_destinationRectangle1.h = m_sourceRectangle1.h;

        //��������/�������� ��ġ ����
        m_destinationRectangle1.x = m_sourceRectangle1.x = 130;
        m_destinationRectangle1.y = m_sourceRectangle1.y = 0;

        m_bRunning = true;
        m_turn = true;

        return true;
    }

    
}

void Game::update()
{
    m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 6);
    m_sourceRectangle_1.x = 128 * ((SDL_GetTicks() / 150) % 6);
    m_sourceRectangle1.x = 67* ((SDL_GetTicks() / 100) % 8);
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderCopy(m_pRenderer, m_pTexture_1, &m_sourceRectangle_1, &m_destinationRectangle_1);
    SDL_RenderCopy(m_pRenderer, m_pugegg, &m_sourceRectangle1, &m_destinationRectangle1);
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
    SDL_DestroyTexture(m_pTexture); // �߰�
    SDL_DestroyTexture(m_pugegg);
    SDL_Quit();
}


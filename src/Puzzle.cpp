#include "Game.h"
#include "Puzzle.h"
#include "InputHandler.h"
#include "GameManager.h"


Puzzle::Puzzle(const LoaderParams* pParams) : SDLGameObject(pParams) { randpuzzle(); }

void Puzzle::draw()
{
    TheTextureManager::Instance()->drawFrame(m_textureID, puzzle_x[puzzle_i[0]], puzzle_y[puzzle_i[0]], 183, 183, m_currentRow * 3 + 0, m_currentFrame * 3 + 0, TheGame::Instance()->getRenderer()); // 0,0
    TheTextureManager::Instance()->drawFrame(m_textureID, puzzle_x[puzzle_i[1]], puzzle_y[puzzle_i[1]], 183, 183, m_currentRow * 3 + 0, m_currentFrame * 3 + 1, TheGame::Instance()->getRenderer()); // 0,1
    TheTextureManager::Instance()->drawFrame(m_textureID, puzzle_x[puzzle_i[2]], puzzle_y[puzzle_i[2]], 183, 183, m_currentRow * 3 + 0, m_currentFrame * 3 + 2, TheGame::Instance()->getRenderer()); // 0,2

    TheTextureManager::Instance()->drawFrame(m_textureID, puzzle_x[puzzle_i[3]], puzzle_y[puzzle_i[3]], 183, 183, m_currentRow * 3 + 1, m_currentFrame * 3 + 0, TheGame::Instance()->getRenderer()); // 1,0
    TheTextureManager::Instance()->drawFrame(m_textureID, puzzle_x[puzzle_i[4]], puzzle_y[puzzle_i[4]], 183, 183, m_currentRow * 3 + 1, m_currentFrame * 3 + 1, TheGame::Instance()->getRenderer()); // 1,1
    TheTextureManager::Instance()->drawFrame(m_textureID, puzzle_x[puzzle_i[5]], puzzle_y[puzzle_i[5]], 183, 183, m_currentRow * 3 + 1, m_currentFrame * 3 + 2, TheGame::Instance()->getRenderer()); // 1,2

    TheTextureManager::Instance()->drawFrame(m_textureID, puzzle_x[puzzle_i[6]], puzzle_y[puzzle_i[6]], 183, 183, m_currentRow * 3 + 2, m_currentFrame * 3 + 0, TheGame::Instance()->getRenderer()); // 2,0
    TheTextureManager::Instance()->drawFrame(m_textureID, puzzle_x[puzzle_i[7]], puzzle_y[puzzle_i[7]], 183, 183, m_currentRow * 3 + 2, m_currentFrame * 3 + 1, TheGame::Instance()->getRenderer()); // 2,1

    if(TheGameManager::Instance()->m_clear == 1)
        SDLGameObject::draw();
}

void Puzzle::update()
{
    handleInput();
    m_currentFrame = Player::Player_currentFrame;
    m_currentRow = Player::Player_currentRow;
    swutchpuzzle();
    gameClear();
}

void Puzzle::clean()
{

}

void Puzzle::handleInput()
{
    if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && !clickpuzzle) {
        blockswitch();
    }
}

void Puzzle::randpuzzle()
{
    srand(time(NULL));

    int tmp;
    int count = 0;
    int isSame = 0;
    int inversion = 0;
    int arr[9] = { 0,1,2,3,4,5,6,7,8 };
    while (1)
    {
        count = 0;
        inversion = 0;
        while (count < 9)
        {
            isSame = 0;
            tmp = rand() % 9;
            for (int i = 0; i < count; i++) { //중복검사
                if (tmp == puzzle_i[i]) { //중복이 있을때
                    isSame = 1;
                    break;
                }
            }
            if (isSame == 0) { //중복없음
                puzzle_i[count] = tmp;
                count++;
            }

        }

        for (int i = 0; i < 8; i++)
        {
            if (puzzle_i[i] == 8)
            {
                puzzle_i[i] = puzzle_i[8];
                puzzle_i[8] = 8;
                break;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (i == puzzle_i[j])
                {
                    arr[i] = j;
                    break;
                }
            }

        }

        for (int i = 0; i < 8; i++)
        {
            for (int j = i + 1; j < 8; j++)
            {
                if (arr[i] > arr[j])
                    inversion++;
            }
        }

        printf("%d\n", inversion);

        if (inversion % 2 == 0)
            break;
        else
            printf("다시 섞기\n");
    }
    printf("섞기 완료!\n");

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == puzzle_i[j])
            {
                printf("%d ", j);
                break;
            }
        }
        if ((i + 1) % 3 == 0)
            printf("\n");
    }

    //{// 주작용
    //    for (int i = 0; i < 7; i++)
    //    {
    //        puzzle_i[i] = i;
    //    }
    //    puzzle_i[7] = 8;
    //    puzzle_i[8] = 7;
    //}
    
}

void Puzzle::blockswitch()
{

    for (int i = 0; i < 9; i++)
    {
        if (puzzle_i[8] == i)
        {
            switchcode(i);
            break;
        }
    }
}

void Puzzle::switchcode(int innum)
{
    int change = 0;

    // 위
    if (innum - 3 >= 0)
    {
        if ((puzzle_x[puzzle_i[8]] < Player::Palyer_X + 25) && (Player::Palyer_X + 25 < puzzle_x[puzzle_i[8]] + 183)
            && (puzzle_y[puzzle_i[8]] - 183 < Player::Palyer_Y + 25) && (Player::Palyer_Y + 25 < puzzle_y[puzzle_i[8]]))
        {
            for (int i = 0; i < 9; i++)
            {
                if (puzzle_i[i] == innum - 3)
                {
                    change = i;
                    break;
                }
            }
            direction = 0;
            movenum_1 = innum;
            movenum_2 = change;

            if(!clickpuzzle)
                save = puzzle_y[puzzle_i[movenum_2]];

            clickpuzzle = true;
           /* puzzle_i[8] = innum - 3;
            puzzle_i[change] = innum;*/
        }
    }
    // 왼쪽
    if ((innum - 1 >= 0) && (innum - 1 != 2) && (innum - 1 != 5))
    {
        if ((puzzle_x[puzzle_i[8]] - 183 < Player::Palyer_X + 25) && (puzzle_x[puzzle_i[8]] > Player::Palyer_X + 25)
            && (puzzle_y[puzzle_i[8]] < Player::Palyer_Y + 25) && (puzzle_y[puzzle_i[8]] + 183 > Player::Palyer_Y + 25))
        {
            for (int i = 0; i < 9; i++)
            {
                if (puzzle_i[i] == innum - 1)
                {
                    change = i;
                    break;
                }
            }
            direction = 1;
            movenum_1 = innum;
            movenum_2 = change;

            if (!clickpuzzle)
                save = puzzle_x[puzzle_i[movenum_2]];

            clickpuzzle = true;
            /*puzzle_i[8] = innum - 1;
            puzzle_i[change] = innum;*/
        }
    }
    // 오른쪽
    if ((innum + 1 <= 8) && (innum + 1 != 3) && (innum + 1 != 6))
    {
        if ((puzzle_x[puzzle_i[8]] + 183 < Player::Palyer_X + 25) && (puzzle_x[puzzle_i[8]] + 183 + 183 > Player::Palyer_X + 25)
            && (puzzle_y[puzzle_i[8]] < Player::Palyer_Y + 25) && (puzzle_y[puzzle_i[8]] + 183 > Player::Palyer_Y + 25))
        {
            for (int i = 0; i < 9; i++)
            {
                if (puzzle_i[i] == innum + 1)
                {
                    change = i;
                    break;
                }
            }
            direction = 2;
            movenum_1 = innum;
            movenum_2 = change;

            if (!clickpuzzle)
                save = puzzle_x[puzzle_i[movenum_2]];

            clickpuzzle = true;

            /*puzzle_i[8] = innum + 1;
            puzzle_i[change] = innum;*/
        }
    }
    // 아래
    if (innum + 3 <= 8)
    {
        if ((puzzle_x[puzzle_i[8]] < Player::Palyer_X + 25) && (Player::Palyer_X + 25 < puzzle_x[puzzle_i[8]] + 183)
            && (puzzle_y[puzzle_i[8]] + 183 < Player::Palyer_Y + 25) && (Player::Palyer_Y + 25 < puzzle_y[puzzle_i[8]] + 183 + 183))
        {
            for (int i = 0; i < 9; i++)
            {
                if (puzzle_i[i] == innum + 3)
                {
                    change = i;
                    break;
                }
            }
            direction = 3;
            movenum_1 = innum;
            movenum_2 = change;

            if (!clickpuzzle)
                save = puzzle_y[puzzle_i[movenum_2]];

            clickpuzzle = true;

            /*puzzle_i[8] = innum + 3;
            puzzle_i[change] = innum;*/
        }
    }

}

void Puzzle::swutchpuzzle()
{
    
    if (clickpuzzle)
    {
        switch (direction)
        {
        case 0:
            if (puzzle_y[puzzle_i[movenum_2]] < puzzle_y[puzzle_i[8]])
                puzzle_y[puzzle_i[movenum_2]] += movespeed;
            else
            {
                puzzle_y[puzzle_i[movenum_2]] = save;
                puzzle_i[8] = movenum_1 - 3;
                puzzle_i[movenum_2] = movenum_1;
                clickpuzzle = false;
                direction = -1;
            }
            break;

        case 1:
            if (puzzle_x[puzzle_i[movenum_2]] < puzzle_x[puzzle_i[8]])
                puzzle_x[puzzle_i[movenum_2]] += movespeed;
            else
            {
                puzzle_x[puzzle_i[movenum_2]] = save;
                puzzle_i[8] = movenum_1 - 1;
                puzzle_i[movenum_2] = movenum_1;
                clickpuzzle = false;
                direction = -1;
            }
            break;

        case 2:
            if (puzzle_x[puzzle_i[movenum_2]] > puzzle_x[puzzle_i[8]])
                puzzle_x[puzzle_i[movenum_2]] -= movespeed;
            else
            {
                puzzle_x[puzzle_i[movenum_2]] = save;
                puzzle_i[8] = movenum_1 + 1;
                puzzle_i[movenum_2] = movenum_1;
                clickpuzzle = false;
                direction = -1;
            }
            break;

        case 3:
            if (puzzle_y[puzzle_i[movenum_2]] > puzzle_y[puzzle_i[8]])
                puzzle_y[puzzle_i[movenum_2]] -= movespeed;
            else
            {
                puzzle_y[puzzle_i[movenum_2]] = save;
                puzzle_i[8] = movenum_1 + 3;
                puzzle_i[movenum_2] = movenum_1;
                clickpuzzle = false;
                direction = -1;
            }
            break;

        }
    }
}

void Puzzle::gameClear()
{
    for (int i = 0; i < 9; i++)
    {
        if (puzzle_i[i] != i)
            return;

        
    }
    TheGameManager::Instance()->m_clear = 1;
}
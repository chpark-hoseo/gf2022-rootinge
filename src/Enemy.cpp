#include "Enemy.h"
#include "Game.h"



void EnemySystem::InitEnemySystem(void)
{

    for (int i = 0; i < MAX_ENEMY; i++)
    {

        Ene[i].Pos.m_x = 0;
        Ene[i].Pos.m_y = 0;

        Ene[i].Des.m_x = 0;
        Ene[i].Des.m_y = 0;

        Ene[i].IsLive = 0;

        Ene[i].prev = NULL;

    }
    ES.Delay = 300;
    ES.root.prev = &ES.tail;
    ES.tail.prev = &ES.root;
    std::cout << ES.tail.prev << " = " << &ES.root << std::endl;
}

void EnemySystem::NewEnemy()
{

    int i;

    // 먼저, live 가 0인 총알을 찾습니다. 이 부분도 링크드 리스트로 처리해 두면 관리가 더 편리합니다.
    for (i = 0; i < MAX_ENEMY; i++)
    {

        if (!Ene[i].IsLive)
            break;

    }

    // i 의 위치에 임의의 위치를 넣습니다.
    int posx = rand() % 4;

    switch (posx)
    {

    case 0:

        Ene[i].Pos.m_x = -50;
        Ene[i].Pos.m_y = (rand() % 690) - 50;

        break;

    case 1:

        Ene[i].Pos.m_x = (rand() % 690) - 50;
        Ene[i].Pos.m_y = -50;

        break;

    case 2:

        Ene[i].Pos.m_x = 690;
        Ene[i].Pos.m_y = (rand() % 690) - 50;

        break;

    case 3:

        Ene[i].Pos.m_x = (rand() % 690) - 50;
        Ene[i].Pos.m_y = 690;

        break;

    }

    // 위치는 일단 0으로 고정 합니다.
    Ene[i].Des.m_x = 320 - Ene[i].Pos.m_x;
    Ene[i].Des.m_y = 320 - Ene[i].Pos.m_y;
    m_Vector.VectorNormalize(&Ene[i].Des);

    Ene[i].IsLive = 1;

    // 링크드 리스트에 등록 합니다. Tail의 바로 앞에 등록합니다.
    Ene[i].prev = ES.tail.prev;
    ES.tail.prev = &Ene[i];

}


void EnemySystem::ProcessEnemy()
{

    // Delay 값이 0 이면 새로운 총알을 생성하여 넣습니다.
    if (!ES.Delay--)
    {

        NewEnemy();

        ES.Delay = 100;

    }

    // 총알을 이동 시킵니다.
    {
        

        // 총알을 이동 시키고 그립니다.
        for (Enemy* NowPos = ES.tail.prev, *PrevPos = &ES.tail; NowPos != &ES.root;  NowPos = NowPos->prev, PrevPos = PrevPos->prev)
        {
            std::cout << NowPos << " =   " << &ES.root << std::endl;
            Enemynum++;
            // 총알이 화면 밖으로 나갔다면, 총알을 삭제 처리 합니다.
            /*if (NowPos->Des.m_x > 0)
            {

                if (NowPos->Des.m_y > 0)
                {

                    if ((NowPos->Pos.m_x - 50) > 640 || (NowPos->Pos.m_y - 50) > 640)
                    {

                        NowPos->IsLive = 0;
                        PrevPos->prev = NowPos->prev;
                        NowPos = NowPos->prev;

                    }

                }
                else
                {

                    if ((NowPos->Pos.m_x - 50) > 640 || (NowPos->Pos.m_y + 50) < 0)
                    {

                        NowPos->IsLive = 0;
                        PrevPos->prev = NowPos->prev;
                        NowPos = NowPos->prev;

                    }

                }

            }
            else
            {

                if (NowPos->Des.m_y > 0)
                {

                    if ((NowPos->Pos.m_x + 50) < 0 || (NowPos->Pos.m_y - 50) > 640)
                    {

                        NowPos->IsLive = 0;
                        PrevPos->prev = NowPos->prev;
                        NowPos = NowPos->prev;

                    }

                }
                else
                {

                    if ((NowPos->Pos.m_x + 50) < 0 || (NowPos->Pos.m_y + 50) < 0)
                    {

                        NowPos->IsLive = 0;
                        PrevPos->prev = NowPos->prev;
                        NowPos = NowPos->prev;

                    }

                }

            }*/
            

            NowPos->Pos = m_Vector.AddVector(NowPos->Pos, NowPos->Des);

            is_x[Enemynum] = NowPos->Pos.m_x - (50 / 2);
            is_y[Enemynum] = NowPos->Pos.m_y - (50 / 2);
            //TheTextureManager::Instance()->draw("circle", NowPos->Pos.m_x - (50 / 2), NowPos->Pos.m_y - (50 / 2), 50, 50, m_pRenderer);
            std::cout << NowPos->prev << " ==  " << &ES.root << std::endl;
            
            std::cout << NowPos << " === " << &ES.root << std::endl;
        }

    }

}
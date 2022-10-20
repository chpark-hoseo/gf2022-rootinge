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

    // ����, live �� 0�� �Ѿ��� ã���ϴ�. �� �κе� ��ũ�� ����Ʈ�� ó���� �θ� ������ �� ���մϴ�.
    for (i = 0; i < MAX_ENEMY; i++)
    {

        if (!Ene[i].IsLive)
            break;

    }

    // i �� ��ġ�� ������ ��ġ�� �ֽ��ϴ�.
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

    // ��ġ�� �ϴ� 0���� ���� �մϴ�.
    Ene[i].Des.m_x = 320 - Ene[i].Pos.m_x;
    Ene[i].Des.m_y = 320 - Ene[i].Pos.m_y;
    m_Vector.VectorNormalize(&Ene[i].Des);

    Ene[i].IsLive = 1;

    // ��ũ�� ����Ʈ�� ��� �մϴ�. Tail�� �ٷ� �տ� ����մϴ�.
    Ene[i].prev = ES.tail.prev;
    ES.tail.prev = &Ene[i];

}


void EnemySystem::ProcessEnemy()
{

    // Delay ���� 0 �̸� ���ο� �Ѿ��� �����Ͽ� �ֽ��ϴ�.
    if (!ES.Delay--)
    {

        NewEnemy();

        ES.Delay = 100;

    }

    // �Ѿ��� �̵� ��ŵ�ϴ�.
    {
        

        // �Ѿ��� �̵� ��Ű�� �׸��ϴ�.
        for (Enemy* NowPos = ES.tail.prev, *PrevPos = &ES.tail; NowPos != &ES.root;  NowPos = NowPos->prev, PrevPos = PrevPos->prev)
        {
            std::cout << NowPos << " =   " << &ES.root << std::endl;
            Enemynum++;
            // �Ѿ��� ȭ�� ������ �����ٸ�, �Ѿ��� ���� ó�� �մϴ�.
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
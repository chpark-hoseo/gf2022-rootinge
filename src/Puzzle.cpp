#include "Puzzle.h"

Puzzle::Puzzle(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Puzzle::draw()
{

}

void Puzzle::update()
{

}

void Puzzle::clean()
{

}

//void Puzzle::switchcode(int innum)
//{
//    int change = 0;
//
//    // 위
//    if (innum - 3 >= 0)
//    {
//        if ((puzzle_x[puzzle_i[8]] < Player::Palyer_X + 25) && (Player::Palyer_X + 25 < puzzle_x[puzzle_i[8]] + 183)
//            && (puzzle_y[puzzle_i[8]] - 183 < Player::Palyer_Y + 25) && (Player::Palyer_Y + 25 < puzzle_y[puzzle_i[8]]))
//        {
//            for (int i = 0; i < 9; i++)
//            {
//                if (puzzle_i[i] == innum - 3)
//                {
//                    change = i;
//                    break;
//                }
//            }
//
//            puzzle_i[8] = innum - 3;
//            puzzle_i[change] = innum;
//        }
//    }
//    // 왼쪽
//    if ((innum - 1 >= 0) && (innum - 1 != 2) && (innum - 1 != 5))
//    {
//        if ((puzzle_x[puzzle_i[8]] - 183 < Player::Palyer_X + 25) && (puzzle_x[puzzle_i[8]] > Player::Palyer_X + 25)
//            && (puzzle_y[puzzle_i[8]] < Player::Palyer_Y + 25) && (puzzle_y[puzzle_i[8]] + 183 > Player::Palyer_Y + 25))
//        {
//            for (int i = 0; i < 9; i++)
//            {
//                if (puzzle_i[i] == innum - 1)
//                {
//                    change = i;
//                    break;
//                }
//            }
//
//            puzzle_i[8] = innum - 1;
//            puzzle_i[change] = innum;
//        }
//    }
//    // 오른쪽
//    if ((innum + 1 <= 8) && (innum + 1 != 3) && (innum + 1 != 6))
//    {
//        if ((puzzle_x[puzzle_i[8]] + 183 < Player::Palyer_X + 25) && (puzzle_x[puzzle_i[8]] + 183 + 183 > Player::Palyer_X + 25)
//            && (puzzle_y[puzzle_i[8]] < Player::Palyer_Y + 25) && (puzzle_y[puzzle_i[8]] + 183 > Player::Palyer_Y + 25))
//        {
//            for (int i = 0; i < 9; i++)
//            {
//                if (puzzle_i[i] == innum + 1)
//                {
//                    change = i;
//                    break;
//                }
//            }
//
//            puzzle_i[8] = innum + 1;
//            puzzle_i[change] = innum;
//        }
//    }
//    // 아래
//    if (innum + 3 <= 8)
//    {
//        if ((puzzle_x[puzzle_i[8]] < Player::Palyer_X + 25) && (Player::Palyer_X + 25 < puzzle_x[puzzle_i[8]] + 183)
//            && (puzzle_y[puzzle_i[8]] + 183 < Player::Palyer_Y + 25) && (Player::Palyer_Y + 25 < puzzle_y[puzzle_i[8]] + 183 + 183))
//        {
//            for (int i = 0; i < 9; i++)
//            {
//                if (puzzle_i[i] == innum + 3)
//                {
//                    change = i;
//                    break;
//                }
//            }
//
//            puzzle_i[8] = innum + 3;
//            puzzle_i[change] = innum;
//        }
//    }
//
//}
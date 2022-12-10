#include "Piece.h"
#include "Player.h"
#include "Puzzle.h"

Piece::Piece(const LoaderParams* pParams, int x,int y, int i) : SDLGameObject(pParams) {
	seat_x = x;
	seat_y = y;
	seat_i = i;
}

void Piece::draw()
{
	SDLGameObject::draw();
}

void Piece::update()
{
	m_position.setX(Puzzle::puzzle_x[Puzzle::puzzle_i[seat_i]]);
	m_position.setY(Puzzle::puzzle_y[Puzzle::puzzle_i[seat_i]]);

    m_currentFrame = Player::Player_currentFrame * 3 + seat_x;
    m_currentRow = Player::Player_currentRow * 3 + seat_y;

}
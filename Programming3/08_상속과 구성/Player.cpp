#include "Player.h"

Player::Player()
{
	mov = new Moveable;
}

Player::~Player()
{
	delete mov;
}

void Player::Move(int x, int y)
{
	mov->Move(x, y);
}

void Player::Teleport(Pos* pos)
{
	mov->Teleport(pos);
}

void Player::DisplayPos()
{
	cout << "플레이어의 ";
	mov->DisplayPos();
}

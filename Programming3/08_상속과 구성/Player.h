#pragma once

#include "Moveable.h"

using namespace std;

class Player
{
private:
	Moveable* mov;
public:
	Player();
	Player(const Player& other_pos);
	Player(Player&& rhs_pos);
	~Player();

	void Move(int x, int y);
	void Teleport(Pos* pos);
	void DisplayPos();
};


#pragma once

#include "Moveable.h"

using namespace std;

class Monster
{
private:
	Moveable* mov;
public:
	Monster();
	Monster(const Monster& other_pos);
	Monster(Monster&& rhs_pos);
	~Monster();

	void Move(int x, int y);
	void Teleport(Pos* other);
	void DisplayPos();
};

